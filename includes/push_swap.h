/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:53:15 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/12 20:32:52 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct			s_stack
{
	int					value;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

/*
**		Utility functions
*/

t_stack		*new_list(int data);
t_stack		*get_node(t_stack *list, int index);
int			get_index(t_stack *list, t_stack *node);
void		push_list(t_stack **begin, int data);
int			get_list_length(t_stack *list);
int			ft_is_stack_sorted(t_stack  **a);
int			ft_is_stack_decreasing_sorted(t_stack  **b);
t_stack		*create_list();
t_stack		*create_node(int data);
void		delete_list(t_stack	**list);

/*
**		Operators
*/

void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void    	sa(t_stack **a);
void    	sb(t_stack **b);
void    	ss(t_stack **a, t_stack **b);
void		ra(t_stack ** a);
void		rb(t_stack ** b);
void		rr(t_stack **a, t_stack **b);
void    	rra(t_stack **a);
void    	rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

/*
**		Parsing functions
*/

long int 	ft_atoilong(const char *nptr);
void		ft_error(void);
void		ft_malloc_error(void);
int			is_number(char *str);
int			without_duplicate(t_stack *list);
int			check_min_max(long int n);
int     	check_cmd(char *buf);
void		exec_cmd(t_stack **list, t_stack **list_b, char *cmd);
void		parse_arg(t_stack **list, char *str);
void		parse_cmd(t_stack **a, t_stack **b);

/*
**		Sort functions
*/

void		sort_tiny_list(t_stack **list);
void		sort_tiny_list_b(t_stack **list);
void		quicksort_ascending(int size, t_stack **list, t_stack **stock);
void		quicksort_descending(int size, t_stack **list, t_stack **stock);
t_stack		*last_node(t_stack *root);
int			*ft_get_median(t_stack *list, const int size);
t_stack 	*ft_select_pivot(t_stack *list, const int size);

#endif
