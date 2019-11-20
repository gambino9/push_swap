/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:32:39 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/20 13:32:20 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_is_stack_sorted(t_stack **a)
{
	t_stack		*tmp;

	tmp = (*a);
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_is_stack_decreasing_sorted(t_stack **b)
{
	t_stack		*tmp;

	tmp = (*b);
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		get_list_length(t_stack *list)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = list;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
