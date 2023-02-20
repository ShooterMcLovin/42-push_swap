/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:31:11 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/10 16:10:34 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_target(t_stack **a, int head_index, int target_idx, int target_posit)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->index > head_index && temp->index < target_idx)
		{
			target_idx = temp->index;
			target_posit = temp->pos;
		}
		temp = temp->next;
	}
	if (target_idx != INT_MAX)
		return (target_posit);
	temp = *a;
	while (temp)
	{
		if (temp->index < target_idx)
		{
			target_idx = temp->index;
			target_posit = temp->pos;
		}
		temp = temp->next;
	}
	return (target_posit);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*head;
	int		target_index;

	head = *b;
	get_position(a);
	get_position(b);
	target_index = 0;
	while (head)
	{
		target_index = get_target(a, head->index, INT_MAX, target_index);
		head->target_index = target_index;
		head = head->next;
	}
}
