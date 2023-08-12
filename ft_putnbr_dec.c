/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:02:36 by kparadis          #+#    #+#             */
/*   Updated: 2023/07/04 18:13:36 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_dec(int n, int *counter)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", counter);
	else if (n < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr_dec(-n, counter);
	}
	else if (n >= 10)
	{
		ft_putnbr_dec(n / 10, counter);
		ft_putchar(n % 10 + '0', counter);
	}
	else
		ft_putchar(n + '0', counter);
	counter++;
}
