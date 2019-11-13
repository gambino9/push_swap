/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:21:22 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/05 14:51:01 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

// int		main(int argc, char *argv[])
// {
// 	int			i;
// 	t_stack		*list_a;
// 	t_stack		*tmp_a;
// 	t_stack		*list_b;

// 	i = argc;
// 	list_a = create_list();
// 	if (argc <= 1)
// 		return (0);
// 	while (--i != 0)
// 		parse_arg(&list_a, argv[i]);
// 	tmp_a = list_a;
// 	if (!(without_duplicate(list_a)))
// 	{
// 		delete_list(&list_a);
// 		ft_error();
// 	}
// 	list_b = create_list();
// 	parse_cmd(&tmp_a, &list_b);
// 	list_a = tmp_a;
// 	if (list_b == NULL && ft_is_stack_sorted(&tmp_a) == 1)
// 		ft_putendl("OK\n");
// 	else
// 		ft_putendl("KO\n");
// 	delete_list(&list_b);
// 	delete_list(&list_a);
// 	return (0);
// }