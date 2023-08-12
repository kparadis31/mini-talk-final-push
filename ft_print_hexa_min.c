/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:13 by kparadis          #+#    #+#             */
/*   Updated: 2023/07/04 18:13:36 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_hexa_min(unsigned int nbr, int *len)
{
	if (nbr >= 16)
	{
		ft_print_hexa_min((nbr / 16), len);
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
