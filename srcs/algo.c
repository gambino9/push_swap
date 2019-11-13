/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:18:43 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/09 20:00:06 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
**	A utility function to find last node of linked list
*/

t_stack	*last_node(t_stack *root)
{
	while (root && root->next)
		root = root->next;
	return (root);
}

/*
**	Considers last element as pivot, places the pivot element at its 
**	correct position in sorted array, and places all smaller (smaller than 
**	pivot) to left of pivot and all greater elements to right of pivot
*/

t_stack	*partition(t_stack *first, t_stack *last)
{
	int			pivot;
	t_stack		*i;
	t_stack		*j;

	pivot = last->value;
	i = first->prev;
	j = first;
	while (j != last)
	{
		if (j->value <= pivot)
		{
			i = (i == NULL)? first : i->next;
			swap(&(i->value), &(j->value));
		}
		j = j->next;
	}
	i = (i == NULL)? first : i->next;
	swap(&(i->value), &(last->value));
	return (i);
}

 /*
 **	A recursive implementation of quicksort for linked list
 */

void	_quick_sort(t_stack *first, t_stack *last)
{
	if (last != NULL && first != last && first != last->next)
	{
		t_stack	*p;
		p = partition(first, last);
		_quick_sort(first, p->prev);
		_quick_sort(p->next, last);
	}
}

/*
**	The main function to sort a linked list. It mainly calls _quickSort()
*/

void	quick_sort(t_stack *head)
{
	t_stack *last;

	last = last_node(head);
	_quick_sort(head, last);
}

/*
**	Function to insert a node at the beginning of the Doubly Linked List
*/

void	push(t_stack **head_ref, int new_data)
{
	t_stack	*new_node;

	if ((new_node = ((t_stack*)ft_memalloc(sizeof(t_stack )))) == NULL)
		return ;
	
	new_node->value = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

/*int		main(int argc, char *argv[])
{
	t_stack *a;
	t_stack	*tmp;

	a = create_list();
	if (argc <= 1)
		return (0);
	printf("avant les args\n");
	while (argc != 1)
	{
		push_list(&a, ft_atoi(argv[argc - 1]));
		argc--;
	}
	tmp = a;
	while (a != NULL)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	printf("-------------------------------------------\n");
	quick_sort(tmp);
	while (tmp != NULL)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}*/