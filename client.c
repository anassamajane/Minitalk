#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void    send_bit(int pid, char c)
{
        int     bit;

        bit = 7;
        while (bit >= 0)
        {
                if (((c >> bit) & 1) == 1)
		{
                        kill(pid, SIGUSR2);
			ft_printf("sent bit: 0\n");
		}
                else
		{
                        kill(pid, SIGUSR1);
			ft_printf("sent bit: 1\n");
		}
                usleep(600);
		bit--;
        }
}

int     main(int ac, char **av)
{
        int     pid;
        int     i;

        if (ac != 3)
        {
                ft_printf("Usage: %s <PID> <message>\n", av[0]);
                return (1);
        }
        pid = atoi(av[1]);
        i = 0;
        while (av[2][i])
        {
                send_bit(pid, av[2][i]);
                i++;
        }
        return (0);
}
