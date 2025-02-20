/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:51:40 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/20 15:04:08 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** Puts first node of stack b on top of stack a
*/

void	pa(t_stack **a, t_stack **b)
{
	t_stack *tmp_a;

	if (*b)
	{
		tmp_a = (*a);
		(*a) = (*b);
		(*b) = (*b)->next;
		(*a)->prev = NULL;
		if ((*b) != NULL)
			(*b)->prev = NULL;
		(*a)->next = tmp_a;
		if (tmp_a != NULL)
			tmp_a->prev = (*a);
	}
}

/*
** Puts first node of stack a on top of stack b
*/

void	pb(t_stack **a, t_stack **b)
{
	t_stack *tmp_b;

	if (*a)
	{
		tmp_b = (*b);
		(*b) = (*a);
		(*a) = (*a)->next;
		(*b)->prev = NULL;
		if ((*a) != NULL)
			(*a)->prev = NULL;
		(*b)->next = tmp_b;
		if (tmp_b != NULL)
			tmp_b->prev = (*b);
	}
}
