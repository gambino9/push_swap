/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:51:40 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/23 18:55:47 by lboukrou         ###   ########.fr       */
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
		(*b)->prev = NULL;
		(*a)->next = tmp_a;
		tmp_a->prev = (*a);
	}
}

/*
** Puts first node of stack a on top of stack b
*/

void	pb(t_stack **b, t_stack **a)
{
	t_stack *tmp_b;

	if (*a)
	{
		tmp_b = (*b);

		(*b) = (*a);
		(*a) = (*b)->next;
		(*b)->prev = NULL;
		(*a)->prev = NULL;
		(*b)->next = tmp_b;
		tmp_b->prev = (*b);
	}
}