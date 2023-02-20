/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:44:25 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/08 16:32:36 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	shift_stack(t_stack **a)
{
	int	min;
	int	size;

	size = stk_len(*a);
	min = get_lowest_index_posit(a);
	if (min > size / 2)
	{
		while (min < size)
		{
			ft_rra(a);
			min++;
		}
	}
	else
	{
		while (min > 0)
		{
			ft_ra(a);
			min--;
		}
	}
}

void	short_sort(t_stack **stack)
{
	int	max;

	if (check_order(*stack))
		return ;
	max = get_max_index(*stack);
	if ((*stack)->index == max)
		ft_ra(stack);
	else if ((*stack)->next->index == max)
		ft_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_sa(stack);
}

void	sort_but_three(t_stack **a, t_stack **b)
{
	int	size;
	int	moves;
	int	i;

	size = stk_len(*a);
	moves = 0;
	i = 0;
	while (size > 6 && i < size && moves < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			ft_pb(a, b);
			moves++;
		}
		else
			ft_ra(a);
		i++;
	}
	while (size - moves > 3)
	{
		ft_pb(a, b);
		moves++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	sort_but_three(stack_a, stack_b);
	short_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!check_order(*stack_a))
		shift_stack(stack_a);
}
