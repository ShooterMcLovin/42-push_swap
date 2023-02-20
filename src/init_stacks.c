/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:51:43 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/20 16:36:07 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

t_stack	**new_stack(int no_lists)
{
	t_stack	**stack;

	stack = ft_calloc(sizeof(t_stack *), no_lists);
	if (!stack)
		return (NULL);
	return (stack);
}

t_stack	*new_list(int num)
{
	t_stack	*new_list;

	new_list = ft_calloc(sizeof(t_stack), 1);
	if (!new_list)
		return (NULL);
	new_list->num = num;
	new_list->pos = -1;
	new_list->index = 0;
	new_list->target_index = -1;
	new_list->cost_a = -1;
	new_list->cost_b = -1;
	new_list->next = NULL;
	return (new_list);
}

int	ft_nod(int num)
{
	int	nod;

	nod = 0;
	while (num > 0)
	{
		num /= 10;
		nod++;
	}
	return (nod + 1);
}
