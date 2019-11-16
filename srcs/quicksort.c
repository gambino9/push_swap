/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:49:28 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/16 20:22:25 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	quicksort_ascending(int size, t_stack **list, t_stack **stock)
{
	int			push_cnt;
	int			pivot;
	// t_stack		*tmp;
	int			rotate;
	int			i;

	rotate = 0;
	if (size <= 3)
	{
		if (get_list_length(*list) < 3)
			toute_petite_liste(list);
		sort_tiny_list(list);
	}
	else
	{
		i = 0;
		push_cnt = 0;
		pivot = (ft_select_pivot(*list, size))->value;
	    // printf("QS_a : pivot = %d\n", pivot);
		while (i < size)
		{
			if ((*list)->value <= pivot)
			{
				pb(list, stock);
				ft_putendl_fd("pb", 1);
				push_cnt++;
			}
			else
			{
				ra(list);
				// printf("++++++++++++++++++++++++++++++++a la raie\n");
				ft_putendl_fd("ra", 1);
				rotate++;
			}
			i++;
		}
		// printf("Qs_a : length = %d -- rotate = %d\n", get_list_length(*list), rotate);
		int len = get_list_length(*list);
		if (rotate < len)
		{
			while (rotate--)
			{
				rra(list);
				ft_putendl_fd("rra", 1);
			}
		}
	    // printf("QS_a : size = %d - push_cnt = %d\n", size, push_cnt);
		quicksort_ascending(size - push_cnt, list, stock);
		quicksort_descending(push_cnt, stock, list);
		// size = get_list_length(*stock);
		while (push_cnt > 0)
		{
			if ((*list)->value > (*stock)->value)
			{
				// printf("QS_a pa %d > %d\n", (*list)->value , (*stock)->value);
				// printf("je fais un pa\n");
				pa(list, stock);
				ft_putendl_fd("pa", 1);
				push_cnt--;
			}
			else
			{
				// printf("es-tu la\n");
				ra(list);
				printf("ou ici ?\n");
				ft_putendl_fd("ra", 1);
				// printf("QS_a mon cul raclette\n");
			}
		}
	}
	// tmp = *list;
	// printf("a = ");
	// while (tmp)
    // {
        // printf("%d - ", tmp->value);
    //     tmp = tmp->next;
    // }
	// printf("\nQS_a END\n");
}

void	quicksort_descending(int size, t_stack **list, t_stack **stock)
{
	int		push_cnt;
	int 	pivot;
	// t_stack	*tmp;
	int		rotate;
	int		i;

	rotate = 0;
	// printf("QS_b BEGIN\n");

	if (size <= 3)
	{
		if (get_list_length(*list) < 3)
			toute_petite_liste_b(list);
		sort_tiny_list_b(list);
	}
	else 
	{
		i = 0;
		push_cnt = 0;
		pivot = (ft_select_pivot(*list, size))->value;
	    // printf("QS_b : pivot = %d\n", pivot);
		while (i < size)
		{
			// printf("QS_b : value %d \n", (*list)->value);
			if ((*list)->value > pivot)
			{
				pa(stock, list);
				ft_putendl_fd("pa", 1);
				push_cnt++;
			}
			else
			{
				rb(list);
				ft_putendl_fd("rb", 1);
				rotate++;
			}
			i++;
		}
		// printf("Qs_d : length = %d -- rotate = %d\n", get_list_length(*list), rotate);
		int len = get_list_length(*list);
		if (rotate < len)
		{
			while (rotate--)
			{
				rrb(list);
				ft_putendl_fd("rrb", 1);
			}
		}
	    // printf("QS_b : size = %d - push_cnt = %d\n", size, push_cnt);
		quicksort_descending(size - push_cnt, list, stock);
		quicksort_ascending(push_cnt, stock, list);
		
		while (push_cnt > 0)
		{
			if ((*list)->value < (*stock)->value)
			{
				// printf("QS_b pb %d < %d\n", (*list)->value , (*stock)->value);
				pb(stock, list);
				ft_putendl_fd("pb", 1);
				push_cnt--;
			}
			else
			{
				rb(list);
				ft_putendl_fd("rb", 1);
				// printf("QS_b mon cul choucroute\n");
			} 
		}
	}
	// tmp = *list;
	// printf("b = ");
	// while (tmp)
    // {
    //     // printf("%d - ", tmp->value);
    //     tmp = tmp->next;
    // }
	// printf("\nQS_b END\n");
}

void	sort_tiny_list(t_stack **list)
{
	if (!list || ft_is_stack_sorted(list))
		return ;
	if ((*list)->value > (*list)->next->value)
		{
			sa(list);
			ft_putendl_fd("sa", 1);
		}
	if (!(*list)->next->next)
		return ;
	if ((*list)->next->value > (*list)->next->next->value)
	{
		ra(list);
		ft_putendl_fd("ra", 1);
		sa(list);
		ft_putendl_fd("sa", 1);
		rra(list);
		ft_putendl_fd("rra", 1);
		if ((*list)->value > (*list)->next->value)
		{
			sa(list);
			ft_putendl_fd("sa", 1);
		}
	}
}

void	sort_tiny_list_b(t_stack **list)
{
	if (!list || ft_is_stack_decreasing_sorted(list))
		return ;
	if ((*list)->value < (*list)->next->value)
	{
		sb(list);
		ft_putendl_fd("sb", 1);
	}
	if (!(*list)->next->next)
		return ;
	if ((*list)->next->value < (*list)->next->next->value)
	{
		rb(list);
		ft_putendl_fd("rb", 1);
		sb(list);
		ft_putendl_fd("sb", 1);
		rrb(list);
		ft_putendl_fd("rrb", 1);
		if ((*list)->value < (*list)->next->value)
		{
			sb(list);
			ft_putendl_fd("sb", 1);
		}
	}
}

void	toute_petite_liste(t_stack **list)
{
	if (!list || ft_is_stack_sorted(list))
		return ;
	if (!(*list)->next->next)
		{
			if ((*list)->value > (*list)->next->value)
				{
					// printf("liste 2 elem\n");
					sa(list);
					ft_putendl_fd("sa", 1);
				}
			return ;
		}
	if ((*list)->value < (*list)->next->value)
	{
		// printf("cas 5\n");
		rra(list);
		ft_putendl_fd("rra", 1);
		if ((*list)->value > (*list)->next->value)
		{
			// printf("cas 4\n");			
			sa(list);
			ft_putendl_fd("sa", 1);
		}
	}
	else if ((*list)->next->value < (*list)->next->next->value) // if b < c
	{
		if ((*list)->value < (*list)->next->next->value) // if a < c
		{
			// printf("cas 2\n");			
			sa(list);
			ft_putendl_fd("sa", 1);
		}
		else
		{
			// printf("cas 3\n");						
			ra(list);
			ft_putendl_fd("ra",  1);
		}
	}
	else
	{
		// printf("cas 1\n");			
		sa(list);
		ft_putendl_fd("sa", 1);
		rra(list);
		ft_putendl_fd("rra", 1);
	}
}

void	toute_petite_liste_b(t_stack **list)
{
	if (!list || ft_is_stack_decreasing_sorted(list))
		return ;
	if (!(*list)->next->next)
	{
		if ((*list)->value < (*list)->next->value)
			{
				sb(list);
				ft_putendl_fd("sb", 1);
			}
		return ;
	}
	if ((*list)->value > (*list)->next->value)
	{
		rrb(list);
		ft_putendl_fd("rrb", 1);
		if ((*list)->value < (*list)->next->value)
		{
			sb(list);
			ft_putendl_fd("sb", 1);
		}
	}
	else if ((*list)->next->value > (*list)->next->next->value)
	{
		if ((*list)->value > (*list)->next->next->value)
		{
			sb(list);
			ft_putendl_fd("sb", 1);
		}
		else
		{
			rb(list);
			ft_putendl_fd("rb",  1);
		}
	}
	else
	{
		sb(list);
		ft_putendl_fd("sb", 1);
		rrb(list);
		ft_putendl_fd("rrb", 1);
	}	
}
