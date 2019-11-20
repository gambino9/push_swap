/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 21:26:44 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/20 15:48:37 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_stack		*list;
	t_stack		*list_b;
	t_stack		*cmds;
	int			size;

	if (argc <= 1)
		return (0);
	list = NULL;
	while (argc-- != 1)
		parse_arg(&list, argv[argc]);
	if (!(without_duplicate(list)))
	{
		delete_list(&list);
		ft_error();
	}
	size = get_list_length(list) + 1;
	cmds = NULL;
	list_b = NULL;
	quicksort_ascending(size, &list, &list_b, &cmds);
	optimization(&cmds);
	print_cmds(cmds);
	delete_list(&list);
	delete_list(&list_b);
	delete_list(&cmds);
	return (0);
}
