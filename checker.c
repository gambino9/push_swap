/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:19:00 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/30 21:32:12 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int		main()
{
    char		*line;

	while (get_next_line(0, &line) > 0)
	{
		if (! (check_op(line)))
			ft_error();
		else
			printf("%s\n", line);
	}
	return (0);
}