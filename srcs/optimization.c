/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:15:54 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/17 20:34:29 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void    which_operation(t_stack **cmds, t_stack **list_a, t_stack **list_b, int ope)
{
	// ft_putendl_fd(g_tab_ope[ope], 1);
	exec_cmd(list_a, list_b, g_tab_ope[ope]);
	add_end_list(cmds, ope);
}

void	print_cmds(t_stack *cmds)
{
	while (cmds)
	{
		ft_putendl_fd(g_tab_ope[cmds->value], 1);
		cmds = cmds->next;
	}
}