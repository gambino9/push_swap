/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:53:15 by lboukrou          #+#    #+#             */
/*   Updated: 2019/11/20 20:38:18 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef enum			e_ope
{
	NO, SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
}						t_ope;

static char				*g_tab_ope[12] =
{
	"no", "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
};

/*
**		Utility functions
*/

void				push_list(t_stack **begin, int data);
int					get_list_length(t_stack *list);
int					ft_is_stack_sorted(t_stack **a);
int					ft_is_stack_decreasing_sorted(t_stack **b);
t_stack				*create_node(int data);
void				delete_list(t_stack	**list);
void				dll_delete_node(t_stack **list, t_stack *del);
void				add_end_list(t_stack **list, int data);

/*
**		Operators
*/

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/*
**		Parsing functions
*/

long int			ft_atoilong(const char *nptr);
void				ft_error(void);
void				ft_malloc_error(void);
int					is_number(char *str);
int					without_duplicate(t_stack *list);
int					check_min_max(long int n);
int					check_cmd(char *buf);
void				exec_cmd(t_stack **list, t_stack **list_b, char *cmd);
void				parse_arg(t_stack **list, char *str);
void				parse_cmd(t_stack **a, t_stack **b);

/*
**		Sort functions
*/

void				quicksort_ascending(int size, t_stack **list,
										t_stack **stock, t_stack **cmds);
void				quicksort_descending(int size, t_stack **list,
										t_stack **stock, t_stack **cmds);
void				sort_tiny_list(t_stack **list, t_stack **cmds);
void				sort_tiny_list_b(t_stack **list, t_stack **cmds);
void				sort_few_elem(t_stack **list, t_stack **cmds);
void				sort_few_elem_b(t_stack **list, t_stack **cmds);
int					*ft_get_median(t_stack *list, const int size);
t_stack				*ft_select_pivot(t_stack *list, const int size);
int					which_operation(t_stack **cmds, t_stack **list_a,
									t_stack **list_b, int ope);
void				print_cmds(t_stack *cmds);
void				optimization(t_stack **cmds);
void				opti_swap(t_stack *tmp);
void				opti_rotate(t_stack *tmp);
void				opti_reverse_rotate(t_stack *tmp);
void				opti_push(t_stack **tmp);
int					partition(int size, t_stack **list, t_stack **stock,
								t_stack **cmds);
int					partition_descending(int size, t_stack **list,
										t_stack **stock, t_stack **cmds);

#endif
