/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 21:26:44 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/01 21:55:24 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

int     main(int argc, char *argv[])
{
    t_stack     *list;
    t_stack     *list_b;
    t_stack     *tmp;

    tmp = list;
    list = create_list();
    if (argc <= 1)
		return (0);
    while (--argc != 1)
		parse_arg(&list, argv[argc]);
    
    if (!(without_duplicate(list)))
	{
		delete_list(&list);
		ft_error();
	}
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
    return (0);
}