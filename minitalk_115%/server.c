/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:16:32 by anaamaja          #+#    #+#             */
/*   Updated: 2025/04/03 20:02:51 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	printnum(int nb)
{
	char	c;

	if (nb >= 10)
		printnum(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	signal_handler(int signum)
{
	static char	c = 0;
	static char	bit = 7;

	if (signum == SIGUSR2)
		c |= (1 << bit);
	if (bit == 0)
	{
		write(1, &c, 1);
		c = 0;
		bit = 8;
	}
	bit--;
}

int	main(void)
{
	write(1, "Server PID: ", 12);
	printnum(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
