/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:49:32 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/19 12:52:07 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

int	check_repeat(t_stack **stk, int nb, char **input)
{
	t_stack	*head;

	head = *stk;
	while (head)
	{
		if (head->num == nb)
		{
			ft_error_free(stk, input);
			return (0);
		}
		head = head->next;
	}
	return (1);
}

int	check_valid(char **av)
{
	int	x;
	int	y;

	x = 1;
	while (av[x])
	{
		y = 0;
		while (av[x][y])
		{
			if (av[x][y] == '-' && (av[x][y + 1] >= '0' && av[x][y + 1] <= '9'))
				y++;
			else if (av[x][y] == ' ' || av[x][y + 1] == ' ')
				y++;
			else if ((av[x][y] < '0' || av[x][y] > '9'))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_num(char **av, t_stack **a)
{
	int	x;
	int	y;

	x = 1;
	while (av[x])
	{
		y = 0;
		while (av[x][y])
		{
			while (av[x][y] == ' ')
				y++;
			if (av[x][y] == '-')
				y++;
			if ((av[x][y] < '0' || av[x][y] > '9'))
			{
				ft_putstr_fd("Error\n", 2);
				free_stack(a);
				exit(0);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	check_limits(long num, t_stack **stack, char **input)
{
	if (num <= INT_MAX && num >= INT_MIN)
		return (1);
	else
	{
		ft_error_free(stack, input);
		return (0);
	}
}

void	ft_return_free(t_stack **stack, char **input)
{
	if (stack)
		free_stack(stack);
	if (input)
		ft_release(input);
	exit(0);
}
