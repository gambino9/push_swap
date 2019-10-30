/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:12:49 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/30 17:59:32 by lboukrou         ###   ########.fr       */
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
			return (0);
		list = list->next;
	}
	return (1);
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

void	delete_list(t_stack	**list)
{
	t_stack		*current;
	t_stack		*next;

	current = *list;
	while(current != NULL)
	{
		// printf("lalala\n");
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

int     get_list_length(t_stack *list)
{
    int		i;
	t_stack	*tmp;
    
    i = 0;
	tmp = list;
    while(tmp->next)
    {
		tmp = tmp->next;
		i++;
    }
	return (i);
}

/*
** returns specific node according to an index 
*/

t_stack *get_node(t_stack *list, int index)
{
	t_stack	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp->next && i != index)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

/*
**	returns the index of a specific node
*/

int		get_index(t_stack *list, t_stack *node)
{
	t_stack *tmp;
	int	i;

	tmp = list;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp == node)
			return i;
		i++;
		tmp = tmp->next;
	}
	return (0);
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

/*
** Creates new doubly linked node 
*/

t_stack	*create_node(int data)
{
	t_stack		*list;

	if (!(list = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return NULL;
	list->value = data;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

t_stack	*create_list()
{
	t_stack	*list;
	
	if (!(list = (t_stack *)ft_memalloc(sizeof(t_stack))))
		ft_error();
	list = NULL; 
	return (list);
}