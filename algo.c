/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:18:43 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/17 20:14:07 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*t_stack     *quick_sort(t_stack *list)
{
    t_stack **pivot;
    t_stack **right;
    t_stack **left;

	(*pivot)->index = list->length;
	(*left)->index = list->index;
	(*right)->index = (list->length - 1);
	check_position_reference(&pivot, &left, &right);
	while ((*left)->index < (*right)->index)
	{
		
	}
}

void    check_position_reference(t_stack **pivot, t_stack **left, t_stack **right)
{   
    if ((*left)->value > (*pivot)->value || (*right)->value < (*pivot)->value)
    {
        if ((*left)->value > (*pivot)->value)
        {
            while((*right)->value < (*pivot)->value)
        		(*right)->index--;
            swap((*left)->value, (*right)->value);
        }
		if ((*right)->value < (*pivot)->value)
			while((*left)->value > (*pivot)->value)
				(*left)->index++;
			swap((*left)->value, (*right)->value);
    }
}*/

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

t_stack	*partition(t_stack *l, t_stack *h)
{
	int			x;
	t_stack		*i;
	t_stack		*j;

	x = h->value;
	i = l->prev;
	j = l;
	while (j != h)
	{
		if (j->value <= x)
		{
			i = (i == NULL)? l : i->next;
			swap(&(i->value), &(j->value));
		}
		j = j->next;
	}
	i = (i == NULL)? l : i->next;
	swap(&(i->value), &(h->value));
	return (i);
}

 /*
 **	A recursive implementation of quicksort for linked list
 */

void	_quick_sort(t_stack *l, t_stack *h)
{
	if (h != NULL && l != h && l != h->next)
	{
		t_stack	*p;
		p = partition(l, h);
		_quick_sort(l, p->prev);
		_quick_sort(p->next, h);
	}
}

/*
**	The main function to sort a linked list. It mainly calls _quickSort()
*/

void	quick_sort(t_stack *head)
{
	t_stack *h;

	h = last_node(head);
	_quick_sort(head, h);
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

int		main()
{
	t_stack *a = NULL;
	
	push(&a, 9);
	push(&a, 5);
	push(&a, 16);
	push(&a, 81);
	push(&a, 2);
	push(&a, 1);
	push(&a, 8);
	push(&a, 23);
	printf("value of a : %d\n", a->value);
	printf("value of a : %d\n", a->next->value);
	printf("value of a : %d\n", a->next->next->value);
	printf("value of a : %d\n", a->next->next->next->value);
	printf("value of a : %d\n", a->next->next->next->next->value);
	printf("value of a : %d\n", a->next->next->next->next->next->value);
	printf("value of a : %d\n", a->next->next->next->next->next->next->value);
	printf("value of a : %d\n", a->next->next->next->next->next->next->next->value);
	printf("-------------------------------------------\n");
	quick_sort(a);
	printf("value of a : %d\n", a->value);
	printf("value of a : %d\n", a->next->value);
	printf("value of a : %d\n", a->next->next->value);
	printf("value of a : %d\n", a->next->next->next->value);
	printf("value of a : %d\n", a->next->next->next->next->value);
	printf("value of a : %d\n", a->next->next->next->next->next->value);
	printf("value of a : %d\n", a->next->next->next->next->next->next->value);
	printf("value of a : %d\n", a->next->next->next->next->next->next->next->value);
	return (0);
}