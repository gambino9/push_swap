/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moncul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:52:18 by lboukrou          #+#    #+#             */
/*   Updated: 2019/10/25 19:54:47 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	check_duplicate(t_stack	**list)
{
	t_stack		*tmp;
	t_stack		*tmp1;

	tmp = *list;
	tmp1 = (*list)->next;
	if ((*list) == NULL || (*list)->next == NULL)
		return ;
	while (tmp != NULL)
	{
		while (tmp1 != NULL)
		{
			if (tmp->value == tmp1->value)
			{
				t_stack	*next;
				
				next = tmp1->next;
				printf("doublon\n");
				tmp1 = next; 
			}
			else
				tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

int     main()
{
    int i = 'p';
    int j = '2';
    int k = 3;
    int l = 4;
    int m = 600;
    int n = 'a';
    int o = 'b';

    printf("nombre: %d et res de isdigit : %d\n", i, ft_atoi("0"));
    printf("nombre: %d et res de isdigit : %d\n", j, ft_isdigit((j)));
    printf("nombre: %d et res de isdigit : %d\n", k, ft_isdigit((k)));
    printf("nombre: %d et res de isdigit : %d\n", l, ft_isdigit((l)));
    printf("nombre: %d et res de isdigit : %d\n", m, ft_isdigit((m)));
    printf("nombre: %d et res de isdigit : %d\n", n, ft_isdigit((n)));
    printf("nombre: %d et res de isdigit : %d\n", o, ft_isdigit((o)));
	return (0);
}