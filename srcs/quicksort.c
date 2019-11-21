/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:49:28 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/21 13:40:28 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quicksort_ascending(int size, t_stack **list, t_stack **stock,
							t_stack **cmds)
{
	int			push_cnt;

	if (ft_is_stack_sorted(list))
		return ;
	if (size <= 3)
	{
		if (get_list_length(*list) < 3)
			sort_tiny_list(list, cmds);
		sort_few_elem(list, cmds);
	}
	else
	{
		push_cnt = partition(size, list, stock, cmds);
		quicksort_ascending(size - push_cnt, list, stock, cmds);
		quicksort_descending(push_cnt, stock, list, cmds);
		while (push_cnt > 0)
		{
			which_operation(cmds, list, stock, PA);
			push_cnt--;
		}
	}
}

int		partition(int size, t_stack **list, t_stack **stock, t_stack **cmds)
{
	int		push_cnt;
	int		pivot;
	int		rotate;
	int		i;
	int		len;

	i = 0;
	push_cnt = 0;
	rotate = 0;
	pivot = (ft_select_pivot(*list, size))->value;
	while (i < size)
	{
		if ((*list)->value <= pivot)
			push_cnt += which_operation(cmds, list, stock, PB);
		else
			rotate += which_operation(cmds, list, stock, RA);
		i++;
	}
	len = get_list_length(*list);
	if (rotate < len)
		while (rotate--)
			which_operation(cmds, list, stock, RRA);
	return (push_cnt);
}

int		partition_descending(int size, t_stack **list, t_stack **stock,
								t_stack **cmds)
{
	int		i;
	int		pivot;
	int		push_cnt;
	int		rotate;
	int		len;

	i = 0;
	push_cnt = 0;
	rotate = 0;
	pivot = (ft_select_pivot(*list, size))->value;
	while (i < size)
	{
		if ((*list)->value > pivot)
			push_cnt += which_operation(cmds, stock, list, PA);
		else
			rotate += which_operation(cmds, stock, list, RB);
		i++;
	}
	len = get_list_length(*list);
	if (rotate < len)
	{
		while (rotate--)
			which_operation(cmds, stock, list, RRB);
	}
	return (push_cnt);
}

void	quicksort_descending(int size, t_stack **list, t_stack **stock,
								t_stack **cmds)
{
	int		push_cnt;

	if (ft_is_stack_decreasing_sorted(list))
		return ;
	if (size <= 3)
	{
		if (get_list_length(*list) < 3)
			sort_tiny_list_b(list, cmds);
		sort_few_elem_b(list, cmds);
	}
	else
	{
		push_cnt = partition_descending(size, list, stock, cmds);
		quicksort_descending(size - push_cnt, list, stock, cmds);
		quicksort_ascending(push_cnt, stock, list, cmds);
		while (push_cnt > 0)
		{
			which_operation(cmds, stock, list, PB);
			push_cnt--;
		}
	}
}
