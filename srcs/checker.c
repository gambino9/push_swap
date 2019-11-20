/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:21:22 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/20 15:07:26 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

int		main(int argc, char *argv[])
{
	t_stack		*list_a;
	t_stack		*tmp_a;
	t_stack		*list_b;

	list_a = NULL;
	if (argc <= 1)
		return (0);
	while (argc-- != 1)
		parse_arg(&list_a, argv[argc]);
	tmp_a = list_a;
	if (!(without_duplicate(list_a)))
	{
		delete_list(&list_a);
		ft_error();
	}
	list_b = NULL;
	parse_cmd(&tmp_a, &list_b);
	list_a = tmp_a;
	if (list_b == NULL && ft_is_stack_sorted(&tmp_a) == 1)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	delete_list(&list_b);
	delete_list(&list_a);
	return (0);
}
