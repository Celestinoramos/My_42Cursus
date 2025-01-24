/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:27:45 by cramos-c          #+#    #+#             */
/*   Updated: 2024/08/15 12:37:00 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}

void	send_signal(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	char		*msg;
	int			server_id;

	if (argc != 3)
	{
		ft_printf ("Argumentos incompletos.\n");
		ft_printf ("Argumentos experados: ./client <PID> <Mensagem>\n");
		return (1);
	}
	server_id = ft_atoi(argv[1]);
	if (server_id <= 0)
	{
		ft_printf ("[ERROR]: PID invalido. \n");
		return (1);
	}
	msg = argv[2];
	while (*msg)
	{
		send_signal (server_id, *msg);
		msg++;
	}
	send_signal (server_id, '\0');
	return (0);
}
