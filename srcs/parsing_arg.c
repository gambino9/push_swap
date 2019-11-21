/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:00:32 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/21 16:00:32 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	ft_atoilong(const char *nptr)
{
	size_t		i;
	long long	retour;
	int			negatif;

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

int			check_min_max(long int n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	else
		return (1);
}

int			is_number(char *str)
{
	if (str[0] == '-')
		str++;
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

int			without_duplicate(t_stack *list)
{
	t_stack		*tmp;
	t_stack		*tmp2;

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

void		parse_arg(t_stack **list, char *str)
{
	char	**string;
	int		i;

	i = 0;
	string = ft_strsplit(str, ' ');
	while (string[i] != NULL)
		i++;
	while (--i >= 0)
	{
		if (!is_number((string[i])))
		{
			delete_list(list);
			ft_error();
		}
		if (check_min_max(ft_atoilong(string[i])) == 0)
		{
			delete_list(list);
			ft_error();
		}
		else
			push_list(list, ft_atoi(string[i]));
		free(string[i]);
	}
	free(string);
}
