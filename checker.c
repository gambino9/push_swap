/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:19:00 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/27 20:01:26 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int     check_op(char *buf)
{
    if (!ft_strcmp(buf, "sa") || !ft_strcmp(buf, "sb") || !ft_strcmp(buf, "ss")
        || !ft_strcmp(buf, "pa") || !ft_strcmp(buf, "pb")
        || !ft_strcmp(buf, "ra") || !ft_strcmp(buf, "rb")
        || !ft_strcmp(buf, "rr") || !ft_strcmp(buf, "rra")
		|| !ft_strcmp(buf, "rrb") || !ft_strcmp(buf, "rrr"))
            return (1);
	else
		return (0);
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