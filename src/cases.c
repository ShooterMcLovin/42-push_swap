/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:48:12 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/20 16:35:16 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error_free(t_stack **stack, char **input)
{
	ft_putstr_fd("Error\n", 2);
	if (stack)
		free_stack(stack);
	if (input)
		ft_release(input);
	exit(0);
}

t_stack	**check_and_create_stack(char **av)
{
	t_stack	**stack;
	int		x;
	char	**input;

	if (check_valid(av))
	{
		stack = new_stack(1);
		if (!stack)
			ft_error_free(NULL, NULL);
		x = 1;
		while (av[x] != NULL)
		{
			input = ft_split(av[x++], ' ');
			if (!input[0])
				ft_return_free(stack, input);
			ft_release(input);
		}
		return (stack);
	}
	else
	{
		ft_error_free(NULL, NULL);
		return (NULL);
	}
}

void	parse_input_and_add_to_stack(t_stack **stack, char **av)
{
	long	num;
	char	**input;
	int		x;
	int		y;

	x = 1;
	y = 0;
	while (av[x] != NULL)
	{
		input = ft_split(av[x++], ' ');
		if (!input[0])
			ft_error_free(stack, input);
		y = 0;
		while (input[y] != NULL)
		{
			num = ft_atoi_ps(input[y++], stack, input);
			if (check_limits(num, stack, input) && check_repeat(stack, num,
					input))
				ft_add_back(stack, new_list(num));
		}
		ft_release(input);
	}
}
