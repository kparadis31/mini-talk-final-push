/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:23:20 by kparadis          #+#    #+#             */
/*   Updated: 2023/08/10 17:45:40 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_printf(const char *name, ...);
int		ft_put_everything(const char *format, va_list args, int len);
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_put_0x(unsigned long nbr, int *counter);
void	ft_putnbr_dec(int n, int *counter);
void	ft_putnbr(unsigned long nbr, int *len);
void	ft_print_hexa_maj(unsigned int number, int *len);
void	ft_unsigned_nbr(unsigned int n, int *counter);
void	ft_put_0x(unsigned long nbr, int *len);
void	ft_print_hexa_min(unsigned int nbr, int *len);

#endif
