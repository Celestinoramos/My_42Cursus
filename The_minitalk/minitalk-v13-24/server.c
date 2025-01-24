/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:21:04 by cramos-c          #+#    #+#             */
/*   Updated: 2024/08/15 12:40:09 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	character_handler(int signal, siginfo_t *info, void *contexto)
{
	static int	bit = 0;
	static int	character;

	(void)contexto;
	if (signal == SIGUSR1)
		character |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (character == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		write(1, &character, 1);
		bit = 0;
		character = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	signal_a;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Erro\n");
		return (1);
	}
	ft_printf ("==================================\n");
	ft_printf ("***********THE MINITALK***********\n");
	ft_printf ("==================================\n");
	ft_printf ("***Welcome to CUMBIÇA'S SERVER****\n");
	ft_printf ("==================================\n");
	ft_printf ("THE SERVER'S PID: %d\n", (int) getpid());
	ft_printf ("==================================\n");
	signal_a.sa_sigaction = character_handler;
	sigemptyset(&signal_a.sa_mask);
	signal_a.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &signal_a, NULL);
		sigaction(SIGUSR2, &signal_a, NULL);
		pause();
	}
	return (0);
}
