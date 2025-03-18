#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int cont = 0;


void wait_and_repeat(pid_t pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	while (1)
	{
		if (cont == 0)
			break ;
		printf("testing\n");

	}
}
void    send_bit(int pid, char c)
{
        int     bit;

        bit = 7;
        while (bit >= 0)
        {
		cont = 1;
		wait_and_repeat(pid, (c >> bit) & 1);
		bit--;
        }
}

void empty_handler(int sig)
{
	cont = 0;
	return ;
}

int     main(int ac, char **av)
{
        int     pid;
        int     i;


        if (ac != 3)
        {
                printf("Usage: %s <PID> <message>\n", av[0]);
                return (1);
        }
	signal(SIGUSR1, empty_handler);
        pid = atoi(av[1]);
        i = 0;
        while (av[2][i])
        {
                send_bit(pid, av[2][i]);
                i++;
        }
        return (0);
}
