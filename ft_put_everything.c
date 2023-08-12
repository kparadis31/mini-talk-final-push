/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_everything.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:48:03 by kparadis          #+#    #+#             */
/*   Updated: 2023/07/04 18:13:36 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_put_everything(const char *format, va_list args, int len)
{
	int	counter;

	counter = 0;
	if (format[len] == 'c')
		ft_putchar(va_arg(args, int), &counter);
	if (format[len] == 's')
		ft_putstr(va_arg(args, char *), &counter);
	if (format[len] == 'p')
		ft_put_0x(va_arg(args, unsigned long), &counter);
	if (format[len] == 'd' || format[len] == 'i')
		ft_putnbr_dec(va_arg(args, int), &counter);
	if (format[len] == 'x')
		ft_print_hexa_min(va_arg(args, int), &counter);
	if (format[len] == 'X')
		ft_print_hexa_maj(va_arg(args, unsigned int), &counter);
	if (format[len] == 'u')
		ft_unsigned_nbr(va_arg(args, unsigned int), &counter);
	if (format[len] == '%')
		ft_putstr("%", &counter);
	return (counter);
}
