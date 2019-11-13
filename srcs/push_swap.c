/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 21:26:44 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/13 19:17:38 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

int     main(int argc, char *argv[])
{
    t_stack		*list;
    t_stack		*list_b;
    t_stack		*tmp;
    int         size;

    list = create_list();
    list_b = create_list();
    if (argc <= 1)
		return (0);
    while (argc-- != 1)
        parse_arg(&list, argv[argc]);
    // printf("parse ok\n");
    if (!(without_duplicate(list)))
	{
		delete_list(&list);
		ft_error();
	}
    // printf("dup ok\n");
    tmp = list;
    size = get_list_length(list) + 1;
    //printf("lengthhhh ok\n");
    while (tmp)
    {
        printf("before %d\n", tmp->value);
        tmp = tmp->next;
    }
    // printf("print ok\n");
    
    // tmp = list;
    tmp = list;
    quicksort_ascending(size, &list, &list_b);
    // list = tmp;
    // printf("sort ok\n");
    while (list)
    {
        printf("after %d\n", list->value);
        list = list->next;
    }
    if (ft_is_stack_sorted(&list))
        printf("liste triee\n");
    else
        printf("liste pas triee\n");
    return (0);
}