/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:36:07 by kparadis          #+#    #+#             */
/*   Updated: 2023/08/10 21:27:52 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_confirmation(int sig)
{
	(void)sig;
	ft_printf("Message received\n");
}

void	length_to_server(pid_t pid, int len)
{
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		if ((len & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

void	char_to_server(pid_t pid, char c)
{
	static int	bit;

	while (bit < 8)
	{
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
	bit = 0;
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	struct sigaction	action;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		action.sa_handler = server_confirmation;
		action.sa_flags = 0;
		sigaction(SIGUSR2, &action, NULL);
		length_to_server(pid, ft_strlen(argv[2]));
		i = 0;
		while (argv[2][i] != '\0')
		{
			char_to_server(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("Missing arguments. Usage: client [PID] [TEXT]\n");
		return (1);
	}
	return (0);
}
