/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:59:21 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/09 12:15:51 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*secd_last;
	t_stack	*last;

	last = ft_lst_last(*stack);
	secd_last = ft_lst_secdlast(*stack);
	head = *stack;
	*stack = last;
	(*stack)->next = head;
	secd_last->next = NULL;
}

void	ft_rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_rrb(b);
}
