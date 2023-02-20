/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:59:20 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/19 12:27:40 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

int	abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	stk_len(t_stack *stk)
{
	int	count;

	count = 0;
	if (!stk)
		return (0);
	while (stk)
	{
		stk = stk->next;
		count++;
	}
	return (count);
}

void	ft_release(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

int	check_order(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

long	ft_atoi_ps(const char *str, t_stack **a, char **input)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (!str)
		ft_error_free(a, input);
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i++] - '0');
		else
			ft_error_free(a, input);
	}
	return (res * sign);
}
