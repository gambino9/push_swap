/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:12:49 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/19 19:38:19 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*
** Creates new doubly linked node 
*/

t_stack	*create_node(int data)
{
	t_stack		*list;

	if (!(list = (t_stack *)ft_memalloc(sizeof(t_stack))))
		ft_malloc_error();
	list->value = data;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

/*
** Function to insert a node at the beginging of the Doubly Linked List
*/

void	push_list(t_stack **begin, int data)
{
	t_stack	*new_node;

	new_node = create_node(data);
	new_node->next = (*begin);
	new_node->prev = NULL;
	if ((*begin) != NULL)
		(*begin)->prev = new_node;
	(*begin) = new_node;
}


void	add_end_list(t_stack **list, int data)
{
	t_stack	*new_node;
	t_stack	*tmp;

	tmp = *list;
	new_node = create_node(data);
	if (*list == NULL)
	{
		new_node->prev = NULL;
		*list = new_node;
		return ;
	}
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	new_node->prev = tmp;
}

void	delete_list(t_stack	**list)
{
	t_stack		*current;
	t_stack		*next;

	if (*list == NULL)
		return ;
	current = *list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

/*
**	Deletes node from doubly linked list
*/

void	dll_delete_node(t_stack **list, t_stack *del)
{
	if (*list == NULL || del == NULL)
		return ;
	if (*list == del)
		(*list) = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free (del);
	return ;
}

