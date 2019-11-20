/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:24:59 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/20 19:31:26 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_few_elem(t_stack **list, t_stack **cmds)
{
	if (!list || ft_is_stack_sorted(list))
		return ;
	if ((*list)->value > (*list)->next->value)
		which_operation(cmds, list, NULL, SA);
	if (!(*list)->next->next)
		return ;
	if ((*list)->next->value > (*list)->next->next->value)
	{
		which_operation(cmds, list, NULL, RA);
		which_operation(cmds, list, NULL, SA);
		which_operation(cmds, list, NULL, RRA);
		if ((*list)->value > (*list)->next->value)
			which_operation(cmds, list, NULL, SA);
	}
}

void	sort_few_elem_b(t_stack **list, t_stack **cmds)
{
	if (!list || ft_is_stack_decreasing_sorted(list))
		return ;
	if ((*list)->value < (*list)->next->value)
	{
		which_operation(cmds, NULL, list, SB);
	}
	if (!(*list)->next->next)
		return ;
	if ((*list)->next->value < (*list)->next->next->value)
	{
		which_operation(cmds, NULL, list, RB);
		which_operation(cmds, NULL, list, SB);
		which_operation(cmds, NULL, list, RRB);
		if ((*list)->value < (*list)->next->value)
		{
			which_operation(cmds, NULL, list, SB);
		}
	}
}

void	sort_tiny_list(t_stack **list, t_stack **cmds)
{
	if (!list || ft_is_stack_sorted(list))
		return ;
	if (!(*list)->next->next)
	{
		if ((*list)->value > (*list)->next->value)
			which_operation(cmds, list, NULL, SA);
	}
	else if ((*list)->value < (*list)->next->value)
	{
		which_operation(cmds, list, NULL, RRA);
		if ((*list)->value > (*list)->next->value)
			which_operation(cmds, list, NULL, SA);
	}
	else if ((*list)->next->value < (*list)->next->next->value)
	{
		if ((*list)->value < (*list)->next->next->value)
			which_operation(cmds, list, NULL, SA);
		else
			which_operation(cmds, list, NULL, RA);
	}
	else
	{
		which_operation(cmds, list, NULL, SA);
		which_operation(cmds, list, NULL, RRA);
	}
}

void	sort_tiny_list_b(t_stack **list, t_stack **cmds)
{
	if (!list || ft_is_stack_decreasing_sorted(list))
		return ;
	if (!(*list)->next->next)
	{
		if ((*list)->value < (*list)->next->value)
			which_operation(cmds, NULL, list, SB);
	}
	else if ((*list)->value > (*list)->next->value)
	{
		which_operation(cmds, NULL, list, RRB);
		if ((*list)->value < (*list)->next->value)
			which_operation(cmds, NULL, list, SB);
	}
	else if ((*list)->next->value > (*list)->next->next->value)
	{
		if ((*list)->value > (*list)->next->next->value)
			which_operation(cmds, NULL, list, SB);
		else
			which_operation(cmds, NULL, list, RB);
	}
	else
	{
		which_operation(cmds, NULL, list, SB);
		which_operation(cmds, NULL, list, RRB);
	}
}
