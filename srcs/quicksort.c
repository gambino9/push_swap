/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:49:28 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/13 19:37:26 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	quicksort_ascending(int size, t_stack **list, t_stack **stock)
{
	int			push_cnt;
	t_stack		*last;
	int			pivot;
	t_stack		*tmp;
	int			rotate;
	int			i;

	rotate = 0;
	printf("QS_a BEGIN\n");
	// size = get_list_length(a);
    // printf("QS_a : size = %d\n", size);
	if (size <= 3)
		sort_tiny_list(list);
	else 
	{
		i = 0;
		push_cnt = 0;
		last = last_node(*list);
		pivot = (ft_select_pivot(*list, size))->value;

	    printf("QS_a : pivot = %d\n", pivot);
		while (i <= size)
		{
			if ((*list)->value <= pivot)
			{
				pb(list, stock);
				push_cnt++;
			}
			else
			{
				ra(list);
				rotate++;
			}
			i++;
		}
		while (rotate--)
		{
			rra(list);
		}
	    printf("QS_a : size = %d - push_cnt = %d\n", size, push_cnt);
		quicksort_ascending(size - push_cnt, list, stock);
		quicksort_descending(push_cnt, stock, list);
		while (push_cnt > 0)
		{
			// printf("value of a : %d || b value %d\n", (*list)->value, (*stock)->value);
			if ((*list)->value > (*stock)->value)
			{
				printf("QS_a pa %d > %d\n", (*list)->value , (*stock)->value);
				pa(list, stock);
				push_cnt--;
			}
			else
			{
				ra(list);
				// rotate++;
				printf("QS_a mon cul raclette\n");
			}
		}
		// while (rotate--)
		// {
		// 	rra(list);
		// }
	}
	tmp = *list;
	printf("a = ");
	while (tmp)
    {
        printf("%d - ", tmp->value);
        tmp = tmp->next;
    }
	printf("\nQS_a END\n");
}

void	quicksort_descending(int size, t_stack **list, t_stack **stock)
{
	int		push_cnt;
	t_stack	*last;
	int 	pivot;
	t_stack	*tmp;
	int		rotate;
	int		i;

	rotate = 0;
	// size = get_list_length(b);
    // printf("QS_b : size = %d\n", size);
	printf("QS_b BEGIN\n");

	if (size <= 3)
		sort_tiny_list_b(list);
	else 
	{
		i = 0;
		push_cnt = 0;
		last = last_node(*list);
		pivot = (ft_select_pivot(*list, size))->value;
		// pivot = ft_pivot(*list);
	    printf("QS_b : pivot = %d\n", pivot);
		while (i <= size)
		{
			printf("QS_b : value %d \n", (*list)->value);
			if ((*list)->value >= pivot)
			{
				pa(stock, list);
				push_cnt++;
			}
			else
			{
				rb(list);
				rotate++;
			}
			
			i++;
		}
		while (rotate--)
		{
			rrb(list);
		}
	    printf("QS_b : size = %d - push_cnt = %d\n", size, push_cnt);
		quicksort_descending(size - push_cnt, list, stock);
		quicksort_ascending(push_cnt, stock, list);
		
		while (push_cnt > 0)
		{
			if ((*list)->value < (*stock)->value)
			{
				printf("QS_b pb %d < %d\n", (*list)->value , (*stock)->value);
				pb(stock, list);
				push_cnt--;
			}
			else
			{
				rb(list);
				// rotate++;
				printf("QS_b mon cul choucroute\n");
			} 
		}
		// while (rotate--)
		// {
		// 	rrb(list);
		// }
	}
	tmp = *list;
	printf("b = ");
	while (tmp)
    {
        printf("%d - ", tmp->value);
        tmp = tmp->next;
    }
	printf("\nQS_b END\n");
}

void	sort_tiny_list(t_stack **list)
{
	if (!list || ft_is_stack_sorted(list))
		return ;
	if ((*list)->value > (*list)->next->value)
		sa(list);
	if (!(*list)->next->next)
		return ;
	if ((*list)->next->value > (*list)->next->next->value)
	{
		ra(list);
		sa(list);
		rra(list);
		if ((*list)->value > (*list)->next->value)
			sa(list);	
	}
}

void	sort_tiny_list_b(t_stack **list)
{
	if (!list || ft_is_stack_decreasing_sorted(list))
		return ;
	if ((*list)->value < (*list)->next->value)
		{
			sb(list);
		printf("sb\n");
		}
	if (!(*list)->next->next)
		return ;
	if ((*list)->next->value < (*list)->next->next->value)
	{
		rb(list);
		printf("rb\n");
		sb(list);
		printf("sb\n");
		rrb(list);
		printf("rrb\n");
		if ((*list)->value < (*list)->next->value)
			{sb(list);	
		printf("sb\n");}
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