/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:53:10 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/09 12:12:53 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	assign_index(t_stack *a, int len)
{
	t_stack	*head;
	t_stack	*highest;
	int		value;

	while (--len > 0)
	{
		head = a;
		value = INT_MIN;
		highest = NULL;
		while (head)
		{
			if (head->num == INT_MIN && head->index == 0)
				head->index = 1;
			if (head->num > value && head->index == 0)
			{
				value = head->num;
				highest = head;
				head = a;
			}
			else
				head = head->next;
		}
		if (highest != NULL)
			highest->index = len;
	}
}

void	get_position(t_stack **stack)
{
	t_stack	*head;
	int		i;

	head = *stack;
	i = 0;
	while (head)
	{
		head->pos = i;
		head = head->next;
		i++;
	}
}

int	get_lowest_index_posit(t_stack **stack)
{
	t_stack	*head;
	int		lowest_index;
	int		lowest_pos;

	head = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = head->pos;
	while (head)
	{
		if (head->index < lowest_index)
		{
			lowest_index = head->index;
			lowest_pos = head->pos;
		}
		head = head->next;
	}
	return (lowest_pos);
}

int	get_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}
