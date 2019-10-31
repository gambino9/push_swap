/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:29:46 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/30 19:27:59 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	ft_putendl_fd("Error\n", 2);
	exit(0);
}

void	ft_malloc_error(void)
{
	ft_putendl_fd("Cannot allocate memory\n", 2);
	exit(0);
}