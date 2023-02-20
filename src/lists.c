/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:17:18 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/08 16:29:09 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_lst_last(t_stack *stack)
{
	while (stack)
	{
		if (stack->next == NULL)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_lst_secdlast(t_stack *stack)
{
	while (stack)
	{
		if (stack->next->next == NULL)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	ft_add_back(t_stack **stack, t_stack *neo)
{
	t_stack	*temp;

	if (*stack == NULL)
		*stack = neo;
	else
	{
		temp = ft_lst_last(*(stack));
		temp->next = neo;
	}
}

void	ft_add_front(t_stack **stack, t_stack *neo)
{
	if (stack && neo)
	{
		neo->next = *stack;
		*stack = neo;
	}
}
