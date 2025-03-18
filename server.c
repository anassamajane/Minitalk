#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"


void    signal_handler(int signum)
{
        static char     c = 0;
        static int      bit = 7;

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

int     main()
{
        ft_printf("Server PID: %d\n", getpid());
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);
        while (1)
                pause();
        return (0);
}
