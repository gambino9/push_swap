/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:59:47 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/20 15:02:56 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
**	shift down all elements of stack by 1. Last element becomes first
*/

void	rra(t_stack **a)
{
	t_stack		*tmp;
	t_stack		*tmp_a;

	if (!*a)
		return ;
	tmp_a = *a;
	tmp = *a;
	while (tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	if (tmp->next)
	{
		tmp->next->next = tmp_a;
		tmp_a = tmp->next;
		tmp->next = NULL;
		tmp_a->next->prev = tmp_a;
		tmp_a->prev = NULL;
		(*a) = tmp_a;
	}
}

void	rrb(t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp_b;

	if (!*b)
		return ;
	tmp_b = *b;
	tmp = *b;
	while (tmp->next && tmp->next->next)
	{
		tmp = tmp->next;
	}
	if (tmp->next)
	{
		tmp->next->next = tmp_b;
		tmp_b = tmp->next;
		tmp->next = NULL;
		tmp_b->next->prev = tmp_b;
		tmp_b->prev = NULL;
		(*b) = tmp_b;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
