/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:56:15 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/31 16:19:37 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
**	shift up all elements of stack by 1. First element becomes last
*/

void	ra(t_stack **a)
{
	t_stack		*tmp;
	t_stack		*tmp_a;

	if (*a && (*a)->next)
	{
		tmp = (*a);
		tmp_a = (*a);
		while (tmp->next)
			tmp = tmp->next;
		(*a) = (*a)->next;
		tmp->next = tmp_a;
		tmp_a->prev = tmp;
		tmp_a->next = NULL;
		(*a)->prev = NULL;
	}
}

void	rb(t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp_b;

	if (*b && (*b)->next)
	{
		tmp = (*b);
		tmp_b = (*b);
		while (tmp->next)
			tmp = tmp->next;
		(*b) = (*b)->next;
		tmp->next = tmp_b;
		tmp_b->prev = tmp;
		tmp_b->next = NULL;
		(*b)->prev = NULL;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}