#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int cont = 0;


unsigned int	ft_atol_parse(char *s)
{
	unsigned long	n;

	n = 0;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + *s++ - '0';
		if (n >= INT_MAX)
			return (INT_MAX);
	}
	if (*s)
		return (INT_MAX);
	return (n);
}

void send_bit_and_wait(pid_t pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	int i = 0;
	while (1)
	{
		if (cont == 0)
			break ;
		i++;
		usleep(1000);
		if (i > 400)
		{
			exit(0);
		}

	}
}
void    send_bit(int pid, char c)
{
        int     bit;

        bit = 7;
        while (bit >= 0)
        {
		cont = 1;
		send_bit_and_wait(pid, (c >> bit) & 1);
		bit--;
        }
}

void empty_handler(int sig)
{
	(void)sig;
	cont = 0;
	return ;
}

void ackn(int sig)
{
	(void)sig;
	printf("Server is happy\n");
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
	signal(SIGUSR2, ackn);
        pid = ft_atol_parse(av[1]);
	if (pid == INT_MAX || pid == 0)
		return (1);
	printf("%d\n", pid);
        i = 0;
        while (av[2][i])
        {
                send_bit(pid, av[2][i]);
                i++;
        }
        send_bit(pid, '\0');
        return (0);
}
