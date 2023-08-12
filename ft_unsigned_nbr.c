/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:34:15 by kparadis          #+#    #+#             */
/*   Updated: 2023/07/04 18:13:36 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_unsigned_nbr(unsigned int n, int *counter)
{
	if (n >= 10)
	{
		ft_unsigned_nbr(n / 10, counter);
		ft_putchar(n % 10 + '0', counter);
	}
	else
		ft_putchar(n + '0', counter);
	counter++;
}
