/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:49:28 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/14 16:25:22 by lboukrou         ###   ########.fr       */
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
		sort_tiny_list(list);
	else 
	{
		i = 0;
		push_cnt = 0;
		pivot = (ft_select_pivot(*list, size))->value;
	    // printf("QS_a : pivot = %d\n", pivot);
		while (i <= size)
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
				ft_putendl_fd("ra", 1);
				rotate++;
			}
			i++;
		}
		while (rotate--)
		{
			rra(list);
			ft_putendl_fd("rra", 1);
		}
	    // printf("QS_a : size = %d - push_cnt = %d\n", size, push_cnt);
		quicksort_ascending(size - push_cnt, list, stock);
		quicksort_descending(push_cnt, stock, list);
		while (push_cnt > 0)
		{
			if ((*list)->value > (*stock)->value)
			{
				// printf("QS_a pa %d > %d\n", (*list)->value , (*stock)->value);
				pa(list, stock);
				ft_putendl_fd("pa", 1);
				push_cnt--;
			}
			else
			{
				ra(list);
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
		sort_tiny_list_b(list);
	else 
	{
		i = 0;
		push_cnt = 0;
		pivot = (ft_select_pivot(*list, size))->value;
	    // printf("QS_b : pivot = %d\n", pivot);
		while (i <= size)
		{
			// printf("QS_b : value %d \n", (*list)->value);
			if ((*list)->value >= pivot)
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
		while (rotate--)
		{
			rrb(list);
			ft_putendl_fd("rrb", 1);
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

// int	main()
// {
// 	t_stack	*moncul;
// 	t_stack	*tmp;
	
// 	moncul = create_list();
// 	push_list(&moncul, 4);
// 	push_list(&moncul, 2);
// 	push_list(&moncul, 9);
// 	tmp = moncul;
// 	while (moncul != NULL)
// 	{
// 		printf("%d\n", moncul->value);
// 		moncul = moncul->next;
// 	}
// 	moncul = tmp;
// 	printf("==========\n");
// 	// sort_three_elem(&moncul);
// 	sort_tiny_list(&moncul);
// 	while (moncul != NULL)
// 	{
// 		// printf("il est ou moncul\n");
// 		printf("%d\n", moncul->value);
// 		moncul = moncul->next;
// 	}
// 	return (0);
// }