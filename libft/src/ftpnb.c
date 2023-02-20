/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpnb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:44:26 by alpicard          #+#    #+#             */
/*   Updated: 2023/02/09 14:14:45 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ftpnb(int base, int nb)
{
	if (nb >= base)
	{
		ftpnb(base, nb % base);
		ftpnb(base, nb / base);
	}
	if (nb < base)
		write(1, &BASE_UP[nb], 1);
}
