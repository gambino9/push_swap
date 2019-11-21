/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:06:08 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/21 13:45:42 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	opti_swap(t_stack *tmp)
{
	t_stack *del;

	del = tmp->next;
	tmp->value = SS;
	dll_delete_node(&tmp, del);
}

void	opti_rotate(t_stack *tmp)
{
	t_stack *del;

	del = tmp->next;
	tmp->value = RR;
	dll_delete_node(&tmp, del);
}

void	opti_reverse_rotate(t_stack *tmp)
{
	t_stack *del;

	del = tmp->next;
	tmp->value = RRR;
	dll_delete_node(&tmp, del);
}

void	opti_push(t_stack **tmp)
{
	t_stack *del;

	del = *tmp;
	dll_delete_node(tmp, del);
	del = *tmp;
	dll_delete_node(tmp, del);
	if (*tmp && (*tmp)->prev)
		(*tmp) = (*tmp)->prev;
}
