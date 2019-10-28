/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:51:47 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/20 18:48:19 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** Returns the largest integral value less than or equal to x
*/

int	ft_floor(int x)
{
	if (x > 0)
		return (x);
	return (x - 1);
}

int partition(int items[], int left, int right) 
{
    int pivot = items[ft_floor(right + left) / 2];
    int l = left;
    int r = right;
	
	printf("** pivot is : %d\n", pivot );
    printf("** left is : %d\n", left );
    printf("** right is : %d\n", right );
    while(l <= r) 
	{
        while(items[l] < pivot) 
		{
            l++;
            printf("l is now pointing to: %d\n", items[l]);
    	}
		while(items[r] > pivot) 
		{
            r--;
             printf("r is now pointing to: %d\n", items[r]);
        }
		if (l <= r) 
		{
             printf("** now swapping l and r pointers: %d, %d\n", items[l], items[r]);
             swap(items, l, r);
             l++;
             r--;
        }
    }
    return l;
}

void swap (int *items, int leftPointerIndex, int rightPointerIndex) {
  
  int tempReference;

	tempReference = items[leftPointerIndex];
	items[leftPointerIndex] = items[rightPointerIndex];
	items[rightPointerIndex] = tempReference;
	return;
}


int	*quick_sort(int *items, int leftIndex, int rightIndex)
{
	int		pivotIndex;

	if (items[i] > 1)
	{
		pivotIndex = partition(items, leftIndex, rightIndex);
		printf("** pivot is :\n", items[pivotIndex]);
		if (leftIndex < pivotIndex - 1)
			quick_sort(items, leftIndex, pivotIndex -1);
		if (pivotIndex < rightIndex)
			quick_sort(items, pivotIndex, rightIndex);
	}
	return (items);
}