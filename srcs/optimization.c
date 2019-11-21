/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:15:54 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/21 13:45:47 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		which_operation(t_stack **cmds, t_stack **list_a, t_stack **list_b,
						int ope)
{
	exec_cmd(list_a, list_b, g_tab_ope[ope]);
	add_end_list(cmds, ope);
	return (1);
}

void	print_cmds(t_stack *cmds)
{
	while (cmds)
	{
		ft_putendl_fd(g_tab_ope[cmds->value], 1);
		cmds = cmds->next;
	}
}

void	optimization(t_stack **cmds)
{
	t_stack *tmp;

	tmp = *cmds;
	while (tmp && tmp->next)
	{
		if ((tmp->value == SA && tmp->next->value == SB)
			|| (tmp->value == SB && tmp->next->value == SA))
			opti_swap(tmp);
		else if ((tmp->value == RA && tmp->next->value == RB)
				|| (tmp->value == RB && tmp->next->value == RA))
			opti_rotate(tmp);
		else if ((tmp->value == RRA && tmp->next->value == RRB)
				|| (tmp->value == RRB && tmp->next->value == RRA))
			opti_reverse_rotate(tmp);
		else if ((tmp->value == PA && tmp->next->value == PB)
				|| (tmp->value == PB && tmp->next->value == PA)
				|| (tmp->value == RA && tmp->next->value == RRA)
				|| (tmp->value == RRA && tmp->next->value == RA)
				|| (tmp->value == RB && tmp->next->value == RRB)
				|| (tmp->value == RRB && tmp->next->value == RB))
			opti_push(&tmp);
		else
			tmp = tmp->next;
	}
}
