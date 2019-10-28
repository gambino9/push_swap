/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:21:22 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/28 19:28:02 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

long int		ft_atoilong(const char *nptr)
{
	size_t				i;
	long long	retour;
	int					negatif;

	i = 0;
	negatif = 1;
	retour = 0;
	while ((nptr[i] == ' ') || (nptr[i] == '\n') || (nptr[i] == '\r') ||
			(nptr[i] == '\f') || (nptr[i] == '\v') || (nptr[i] == '\t'))
		i++;
	if (nptr[i] == '-')
		negatif = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		retour *= 10;
		retour += nptr[i] - '0';
		i++;
		if (retour > 9223372036854775807)
			return (negatif == -1 ? 0 : -1);
	}
	return (retour * negatif);
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
	// TODO rajouter ft_error erreur malloc
}

int		check_min_max(long int n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	else
		return (1);
}

int		is_number(char *str)
{
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

int		without_duplicate(t_stack *list)
{
    t_stack *tmp;
	t_stack *tmp2;

	tmp = list;
	while (tmp != NULL && tmp->next != NULL)
	{
		tmp2 = tmp;
		while (tmp2->next != NULL)
		{
			if (tmp->value == tmp2->next->value)
				return (0);
			else
				tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
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

void	exec_cmd(t_stack **list, t_stack **list_b, char *cmd)
{
	// if (!(*cmd))
	// 	return ;
	if (!(ft_strcmp(cmd, "sa")))
		sa(list);
	else if (!(ft_strcmp(cmd, "sb")))
		sb(list);
	else if (!(ft_strcmp(cmd, "ss")))
		ss(list, list_b);
	else if (!(ft_strcmp(cmd, "pa")))
		pa(list, list_b);
	else if (!(ft_strcmp(cmd, "pb")))
		pb(list, list_b);
	else if (!(ft_strcmp(cmd, "ra")))
		ra(list);
	else if (!(ft_strcmp(cmd, "rb")))
		rb(list);
	else if (!(ft_strcmp(cmd, "rr")))
		rr(list, list_b);
	else if (!(ft_strcmp(cmd, "rra")))
		rra(list);
	else if (!(ft_strcmp(cmd, "rrb")))
		rrb(list);
	else if (!(ft_strcmp(cmd, "rrr")))
		rrr(list, list_b);
}

void	parse_arg(t_stack **list, char *str)
{
	if (!is_number((str)))
	{
		printf("caractere non int\n");
		ft_error();
	}
	if (check_min_max(ft_atoilong(str)) == 0)
	{
		printf("over/underflow\n");
		ft_error();
	}
	else
		push_list(list, ft_atoi(str));
}

int		main(int argc, char *argv[])
{
	t_stack		*list;
	int			i;
	int			a;
	char		*line;
	t_stack		*tmp;

	list = create_list();
	tmp = list;
	i = argc;
	a = argc - 1;
	while (i != 1)
	{
		parse_arg(&tmp, argv[a]);
		a--;
		i--;
	}
	if (!(without_duplicate(tmp)))
	{
		printf("doublons presents\n");
		// rajouter fonction suppresion + free liste
		ft_error();
	}
	// printf("pas de probleme\n");
	while (tmp != NULL)
	{
		printf("---- %d\n", (tmp)->value);
		tmp = (tmp)->next;
	}
	t_stack *list_b;

	tmp = list;
	list_b = create_list();
	while (get_next_line(0, &line) > 0)
	{
		if (! (check_op(line)))
			ft_error();
		exec_cmd(&tmp, &list_b, line);
	}
	while (tmp != NULL)
	{
		printf("++++%d\n", (tmp)->value);
		tmp = (tmp)->next;
	}
	if (list_b == NULL && ft_is_stack_sorted(&tmp))
		ft_putendl("OK\n");
	else
		ft_putendl("KO\n");
	return (0);
}