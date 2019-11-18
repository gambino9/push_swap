/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:49:28 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/18 18:28:07 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	quicksort_ascending(int size, t_stack **list, t_stack **stock, t_stack **cmds)
{
	int			push_cnt;
	int			pivot;
	int			rotate;
	int			i;

	rotate = 0;
	if (size <= 3)
	{
		if (get_list_length(*list) < 3)
			toute_petite_liste(list, cmds);
		sort_tiny_list(list, cmds);
	}
	else
	{
		i = 0;
		push_cnt = 0;
		pivot = (ft_select_pivot(*list, size))->value;
		while (i < size)
		{
			if ((*list)->value <= pivot)
			{
				which_operation(cmds, list, stock, PB);
				push_cnt++;
			}
			else
			{
				which_operation(cmds, list, stock, RA);				
				rotate++;
			}
			i++;
		}
		int len = get_list_length(*list);
		if (rotate < len)
		{
			while (rotate--)
			{
				which_operation(cmds, list, stock, RRA);				
			}
		}
		quicksort_ascending(size - push_cnt, list, stock, cmds);
		quicksort_descending(push_cnt, stock, list, cmds);
		while (push_cnt > 0)
		{
				which_operation(cmds, list, stock, PA);
				push_cnt--;
		}
	}
}

void	quicksort_descending(int size, t_stack **list, t_stack **stock, t_stack **cmds)
{
	int		push_cnt;
	int 	pivot;
	int		rotate;
	int		i;

	rotate = 0;
	if (size <= 3)
	{
		if (get_list_length(*list) < 3)
			toute_petite_liste_b(list, cmds);
		sort_tiny_list_b(list, cmds);
	}
	else 
	{
		i = 0;
		push_cnt = 0;
		pivot = (ft_select_pivot(*list, size))->value;
		while (i < size)
		{
			if ((*list)->value > pivot)
			{
				which_operation(cmds, stock, list, PA);
				push_cnt++;
			}
			else
			{
				which_operation(cmds, stock, list, RB);				
				rotate++;
			}
			i++;
		}
		int len = get_list_length(*list);
		if (rotate < len)
		{
			while (rotate--)
			{
				which_operation(cmds, stock, list, RRB);
			}
		}
		quicksort_descending(size - push_cnt, list, stock, cmds);
		quicksort_ascending(push_cnt, stock, list, cmds);
		
		while (push_cnt > 0)
		{
				which_operation(cmds, stock, list, PB);
				push_cnt--;
		}
	}
}

void	sort_tiny_list(t_stack **list, t_stack **cmds)
{
	if (!list || ft_is_stack_sorted(list))
		return ;
	if ((*list)->value > (*list)->next->value)
		{
			which_operation(cmds, list, NULL, SA);
		}
	if (!(*list)->next->next)
		return ;
	if ((*list)->next->value > (*list)->next->next->value)
	{
		which_operation(cmds, list, NULL, RA);
		which_operation(cmds, list, NULL, SA);
		which_operation(cmds, list, NULL, RRA);
		if ((*list)->value > (*list)->next->value)
		{
			which_operation(cmds, list, NULL, SA);
		}
	}
}

void	sort_tiny_list_b(t_stack **list, t_stack **cmds)
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

void	toute_petite_liste(t_stack **list, t_stack **cmds)
{
	if (!list || ft_is_stack_sorted(list))
		return ;
	if (!(*list)->next->next)
		{
			if ((*list)->value > (*list)->next->value)
				{
					which_operation(cmds, list, NULL, SA);
				}
			return ;
		}
	if ((*list)->value < (*list)->next->value)
	{
		which_operation(cmds, list, NULL, RRA);
		if ((*list)->value > (*list)->next->value)
		{
			which_operation(cmds, list, NULL, SA);
		}
	}
	else if ((*list)->next->value < (*list)->next->next->value) // if b < c
	{
		if ((*list)->value < (*list)->next->next->value) // if a < c
		{
			which_operation(cmds, list, NULL, SA);
		}
		else
		{
			which_operation(cmds, list, NULL, RA);
		}
	}
	else
	{
		which_operation(cmds, list, NULL, SA);
		which_operation(cmds, list, NULL, RRA);
	}
}

void	toute_petite_liste_b(t_stack **list, t_stack **cmds)
{
	if (!list || ft_is_stack_decreasing_sorted(list))
		return ;
	if (!(*list)->next->next)
	{
		if ((*list)->value < (*list)->next->value)
			{
				which_operation(cmds, NULL, list, SB);
			}
		return ;
	}
	if ((*list)->value > (*list)->next->value)
	{
		which_operation(cmds, NULL, list, RRB);
		if ((*list)->value < (*list)->next->value)
		{
			which_operation(cmds, NULL, list, SB);
		}
	}
	else if ((*list)->next->value > (*list)->next->next->value)
	{
		if ((*list)->value > (*list)->next->next->value)
		{
			which_operation(cmds, NULL, list, SB);
		}
		else
		{
			which_operation(cmds, NULL, list, RB);
		}
	}
	else
	{
		which_operation(cmds, NULL, list, SB);
		which_operation(cmds, NULL, list, RRB);
	}	
}