/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:50:54 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/14 12:57:18 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*head;

	if (*src == NULL)
		return ;
	head = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = head;
}

void	ft_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}

void	ft_pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}
