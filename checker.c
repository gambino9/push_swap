/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:21:22 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/31 19:00:18 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

int		main(int argc, char *argv[])
{
	int			i;
	t_stack		*list;
	t_stack		*tmp;
	t_stack		*list_b;

	i = argc;
	list = create_list();
	if (argc <= 1)
		return (0);
	while (--i != 0)
		parse_arg(&list, argv[i]);
	tmp = list;
	if (!(without_duplicate(list)))
	{
		delete_list(&list);
		ft_error();
	}
	list_b = create_list();
	parse_cmd(&tmp, &list_b);
	list = tmp;
	if (list_b == NULL && ft_is_stack_sorted(&tmp) == 1)
		ft_putendl("OK\n");
	else
		ft_putendl("KO\n");
	delete_list(&list_b);
	delete_list(&list);
	return (0);
}