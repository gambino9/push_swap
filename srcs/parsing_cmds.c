/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:58:49 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/21 18:04:22 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_cmd(char *buf)
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

void	exec_cmd(t_stack **list, t_stack **list_b, char *cmd)
{
	if (!(ft_strcmp(cmd, "sa")))
		sa(list);
	else if (!(ft_strcmp(cmd, "sb")))
		sb(list_b);
	else if (!(ft_strcmp(cmd, "ss")))
		ss(list, list_b);
	else if (!(ft_strcmp(cmd, "pa")))
		pa(list, list_b);
	else if (!(ft_strcmp(cmd, "pb")))
		pb(list, list_b);
	else if (!(ft_strcmp(cmd, "ra")))
		ra(list);
	else if (!(ft_strcmp(cmd, "rb")))
		rb(list_b);
	else if (!(ft_strcmp(cmd, "rr")))
		rr(list, list_b);
	else if (!(ft_strcmp(cmd, "rra")))
		rra(list);
	else if (!(ft_strcmp(cmd, "rrb")))
		rrb(list_b);
	else if (!(ft_strcmp(cmd, "rrr")))
		rrr(list, list_b);
}

void	parse_cmd(t_stack **a, t_stack **b)
{
	char		*line;
	int			ret;

	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!(check_cmd(line)))
		{
			delete_list(a);
			delete_list(b);
			free(line);
			ft_error();
		}
		exec_cmd(a, b, line);
		free(line);
	}
	if (ret == -1)
	{
		free(line);
		ft_error();
	}
}
