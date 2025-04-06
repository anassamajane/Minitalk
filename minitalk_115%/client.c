/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:12:29 by anaamaja          #+#    #+#             */
/*   Updated: 2025/04/06 12:52:27 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_error_and_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	validate_and_convert_pid(char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			display_error_and_exit("incorrect PID\n");
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			display_error_and_exit("incorrect PID\n");
		i++;
	}
	if (result == 0)
		display_error_and_exit("incorrect PID\n");
	return ((int)result);
}

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
		display_error_and_exit("Error sending signal\n");
	usleep(800);
}

void	send_bit(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			send_signal(pid, SIGUSR2);
		else
			send_signal(pid, SIGUSR1);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		display_error_and_exit("Usage: <PID> <message>\n");
	pid = validate_and_convert_pid(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_bit(pid, av[2][i]);
		i++;
	}
	send_bit(pid, '\0');
	return (0);
}
