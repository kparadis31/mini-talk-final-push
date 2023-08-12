/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kparadis <je73@hotmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:36:12 by kparadis          #+#    #+#             */
/*   Updated: 2023/08/10 19:11:57 by kparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_receive_data
{
	unsigned char		received_char;
	int					bit_count;
	char				*received_message;
	int					message_len;
	int					message_index;
}						t_receive_data;

static t_receive_data	g_data;

void	receive_length(int sig)
{
	static int	bit;
	static int	len;

	if (sig == SIGUSR1)
		len |= (1 << bit);
	bit++;
	if (bit == 32)
	{
		g_data.message_len = len;
		g_data.received_message = (char *)malloc(g_data.message_len + 1);
		if (!g_data.received_message)
		{
			ft_printf("Error: Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}
		len = 0;
		bit = 0;
	}
}

void	receive_data(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_data.message_len == 0)
	{
		receive_length(sig);
		return ;
	}
	if (sig == SIGUSR1)
		g_data.received_char |= (1 << g_data.bit_count);
	g_data.bit_count++;
	if (g_data.bit_count == 8)
	{
		g_data.received_message[g_data.message_index] = g_data.received_char;
		g_data.message_index++;
		g_data.received_char = 0;
		g_data.bit_count = 0;
		if (g_data.message_index == g_data.message_len)
		{
			write(1, g_data.received_message, g_data.message_len);
			kill(info->si_pid, SIGUSR2);
			free(g_data.received_message);
			g_data.received_message = NULL;
			g_data.message_len = 0;
			g_data.message_index = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	action;

	(void)argv;
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	g_data.message_len = 0;
	g_data.message_index = 0;
	g_data.received_char = 0;
	g_data.bit_count = 0;
	g_data.received_message = NULL;
	action.sa_sigaction = receive_data;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	if (argc != 1)
	{
		ft_printf("Error: This server does not take any arguments.\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
