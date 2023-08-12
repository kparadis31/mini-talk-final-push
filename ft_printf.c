/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmailcom>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:25:34 by kparadis          #+#    #+#             */
/*   Updated: 2023/01/16 21:58:48 by kparadis         ###   ########fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_c(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		final_len;
	va_list	arg;

	len = 0;
	final_len = 0;
	va_start(arg, format);
	while (format[len])
	{
		if (format[len] == '%' && ++len)
		{
			final_len += ft_put_everything(format, arg, len);
			len++;
		}
		else
			ft_putchar(format[len++], &final_len);
	}
	va_end(arg);
	return (final_len);
}
