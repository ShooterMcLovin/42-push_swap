/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:01:48 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/09 12:49:20 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = *stack;
	*stack = (*stack)->next;
	last = ft_lst_last(*stack);
	head->next = NULL;
	last->next = head;
}

void	ft_ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
}
