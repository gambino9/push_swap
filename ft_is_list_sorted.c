/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_list_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:02:06 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/06 20:15:53 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		ft_is_stack_sorted(t_stack  **a)
{
	t_stack		*list;

	list = (*a);
	while (list && list->next)
	{
		if (list->value > list->next->value)
		{
			printf("pas triee\n");
			return (0);
		}
		list = list->next;
	}
	return (1);
}

int		main()
{
	t_stack	*t;
	t_stack *t1;
	t_stack *t2;
	t_stack *t3;
	t_stack *t4;
	t_stack *t5;
	t_stack *t6;

    t = (t_stack*)ft_memalloc(sizeof(t_stack));
	t1 = (t_stack*)ft_memalloc(sizeof(t_stack));
	t2 = (t_stack*)ft_memalloc(sizeof(t_stack));
	t3 = (t_stack*)ft_memalloc(sizeof(t_stack));
	t4 = (t_stack*)ft_memalloc(sizeof(t_stack));
	t5 = (t_stack*)ft_memalloc(sizeof(t_stack));
	t6 = (t_stack*)ft_memalloc(sizeof(t_stack));
    t->next = t1;
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	t4->next = t5;
	t5->next = t6;
	t6->next = NULL;
    
	t->value = 2;
    t1->value = 4;
	t2->value = 6;
	t3->value = 8;
	t4->value = 10;
	t5->value = 12;
	t6->value = 11;
	printf("%d\n", ft_is_stack_sorted(&t));
	return (0);
}