#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

pid_t sender_pid = 0;

void    signal_handler(int signum, siginfo_t *info, void *ucontext)
{
        static char     c = 0;
        static int      bit = 7;
	 pid_t sender = info->si_pid;


	if (sender_pid != sender)
	{
		c = 0;
		bit = 7;
	}
	sender_pid = sender;
        if (signum == SIGUSR2)
                c |= (1 << bit);
        if (bit == 0)
        {
		write(1, &c, 1);
                c = 0;
                bit = 8;
        }
        bit--;
	kill(sender_pid, SIGUSR1);
}       

int     main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		printf("Error\n");
		return (1);
	}
	struct sigaction info = {0};
	info.sa_sigaction = signal_handler;
	info.sa_flags = SA_SIGINFO;
        printf("Server PID: %d\n", getpid());
        sigaction(SIGUSR1, &info, NULL);
        sigaction(SIGUSR2, &info, NULL);
	while (1)
		pause();
	return (0);
}
