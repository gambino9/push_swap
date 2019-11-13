/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:45:34 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/12 20:36:22 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>


static void     ft_bubble_sort(int *tab, const int size)
{
	int		i;
	int		j;
	int		tmp;

	i = size - 1;
	j = 0;
	while (i >= 0)
	{
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		j = 0;
		i--;
	}
}

static void	ft_fill_tab(t_stack *list, int *unsorted_tab, const int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		unsorted_tab[i] = list->value;
		i++;
		list = list->next;
	}
}

static int	*ft_calc_median(t_stack	*list, int *unsorted_tab, const int size)
{
	int		i;
	int		*median_ptr;

	i = 0;
	median_ptr = (int*)ft_memalloc(sizeof(int));
	if (median_ptr == NULL)
		return NULL;
	ft_fill_tab(list, unsorted_tab, size);
	ft_bubble_sort(unsorted_tab, size);
	if (size % 2  == 0 && size != 2)
		*median_ptr = unsorted_tab[(size / 2) - 1];
	else if (size == 2)
		*median_ptr = unsorted_tab[1];
	else
		*median_ptr = unsorted_tab[(size / 2)];
	return (median_ptr);
}

int		*ft_get_median(t_stack *list, const int size)
{
	int		*unsorted_tab;
	int		*median;

	unsorted_tab = (int*)ft_memalloc(size * sizeof(int));
	if (unsorted_tab == NULL)
		return NULL;
	median = ft_calc_median(list, unsorted_tab, size);
	ft_memdel((void**)&unsorted_tab);
	return (median);
}

t_stack *ft_select_pivot(t_stack *list, const int size)
{
	int		*median;

	median = ft_get_median(list, size);
	if (median == NULL)
		return NULL;
	while (list->value != *median)
		list = list->next;
	ft_memdel((void**)&median);
	return (list);
}