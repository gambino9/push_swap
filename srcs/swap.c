/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:42:55 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/08 19:20:47 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    sa(t_stack **a)
{
	t_stack *tmp;

	if ((*a) && (*a)->next)
	{
        tmp = (*a);
        (*a) = (*a)->next;

        tmp->next = (*a)->next;
        if (tmp->next != NULL)
            tmp->next->prev = tmp;

        (*a)->prev = tmp->prev;
        (*a)->next = tmp;
	}
}

void    sb(t_stack **b)
{
	t_stack *tmp;

	if ((*b) && (*b)->next)
	{
		tmp = (*b);
        (*b) = (*b)->next;

        tmp->next = (*b)->next;
        if (tmp->next != NULL)
            tmp->next->prev = tmp;

        (*b)->prev = tmp->prev;
        (*b)->next = tmp;
	}
}

void    ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
}