/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 07:39:02 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/20 16:35:35 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				pos;
	int				target_index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

t_stack				**new_stack(int no_lists);
t_stack				*new_list(int num);
t_stack				*ft_lst_last(t_stack *stack);
t_stack				*ft_lst_secdlast(t_stack *stack);
t_stack				**check_and_create_stack(char **av);
void				parse_input_and_add_to_stack(t_stack **stack, char **av);
long				ft_atoi_ps(const char *str, t_stack **a, char **input);

int					check_num(char **av, t_stack **a);
int					check_repeat(t_stack **stk, int nb, char **input);
int					check_order(t_stack *stack);
int					check_limits(long num, t_stack **stack, char **input);
int					check_valid(char **av);

void				ft_add_back(t_stack **stack, t_stack *neo);

void				sort(t_stack **stack_a, t_stack **stack_b);
void				short_sort(t_stack **stack);
void				sort_but_three(t_stack **a, t_stack **b);

void				assign_index(t_stack *a, int len);
void				get_target_position(t_stack **a, t_stack **b);
int					get_max_index(t_stack *stack);
void				get_cost(t_stack **stack_a, t_stack **stack_b);
void				get_position(t_stack **stack);
int					get_lowest_index_posit(t_stack **stack);

void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void				do_rotate_b(t_stack **b, int *cost);
void				do_rotate_a(t_stack **a, int *cost);
void				do_rev_rotate_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
void				do_rotate_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);

void				ft_sa(t_stack **a);
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
void				ft_ra(t_stack **a);
void				ft_rb(t_stack **b);
void				ft_rr(t_stack **a, t_stack **b);
void				ft_rra(t_stack **a);
void				ft_rrb(t_stack **b);
void				ft_rrr(t_stack **a, t_stack **b);

int					stk_len(t_stack *stk);
int					abs(int num);

void				ft_release(char **tab);
void				ft_error_free(t_stack **stack, char **input);
void				ft_return_free(t_stack **stack, char **input);
void				free_stack(t_stack **stack);

void				ft_print_lst(t_stack **lst);
#endif
