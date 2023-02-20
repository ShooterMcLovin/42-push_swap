/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:58:38 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/09 12:16:10 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	ft_sa(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}
