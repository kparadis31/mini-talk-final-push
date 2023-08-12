/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:14:05 by kparadis          #+#    #+#             */
/*   Updated: 2023/07/04 18:13:36 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_hexa_maj(unsigned int number, int *len)
{
	if (number >= 16)
	{
		ft_print_hexa_maj((number / 16), len);
		ft_print_hexa_maj((number % 16), len);
	}
	else if (number < 10)
	{
		ft_putchar((number + 48), len);
	}
	else
	{
		ft_putchar((number + 55), len);
	}
}
