/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:41:47 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/20 19:14:13 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_floor(int x)
{
	if (x > 0)
		return (x);
	return (x - 1);
}

t_stack	*partition2(t_stack	*list, t_stack *gauche, t_stack *droit)
{
	int	pivot;
	t_stack *g;
	t_stack *d;

    pivot = ft_floor((get_index(list, gauche) + get_index(list, droit)) / 2);
    g = gauche;
    d = droit;
    
}