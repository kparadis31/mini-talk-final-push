/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:04:59 by kparadis          #+#    #+#             */
/*   Updated: 2023/07/04 18:13:36 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(unsigned long nbr, int *len)
{
	if (nbr >= 16)
	{
		ft_putnbr((nbr / 16), len);
		nbr = nbr % 16;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48, len);
	}
	else
	{
		ft_putchar(nbr + 87, len);
	}
}

void	ft_put_0x(unsigned long nbr, int *counter)
{
	ft_putstr("0x", counter);
	ft_putnbr(nbr, counter);
}
