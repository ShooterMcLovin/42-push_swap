/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:39:44 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/20 16:35:48 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(stack);
}

void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !check_order(*a))
		ft_sa(a);
	else if (size == 3)
		short_sort(a);
	else if (size > 3 && !check_order(*a))
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	**a;
	t_stack	**b;

	if (ac < 2)
		return (0);
	a = check_and_create_stack(av);
	if (a != NULL)
		parse_input_and_add_to_stack(a, av);
	if (!a)
		ft_error_free(a, NULL);
	b = new_stack(stk_len(*a));
	if (!b)
	{
		ft_error_free(a, NULL);
		ft_error_free(b, NULL);
	}
	assign_index(*a, stk_len(*a) + 1);
	if (!check_order(*a))
		push_swap(a, b, stk_len(*a));
	free_stack(a);
	if (b)
		free_stack(b);
	return (0);
}
