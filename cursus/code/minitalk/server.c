#include "minitalk.h"

void handle_signal(int sig,siginfo_t *info,void *context)
{
    static char c = 0;
    static int base = 0;

    (void)info;
	(void)context;
    if (sig == SIGUSR2)
		ch = ch | 128 >> counter;
	counter++;
	if (counter == 8)
	{
		write(1, &ch, 1);
		ch = 0;
		counter = 0;
	}
}

int main(void)
{
    int pid;
    struct sigaction sa1;
    struct sigaction sa2;

    pid = getpid();
    printf(" PID :: %d \n",pid);
    sa1.sa_flags = SA_SIGINFO;
    sa1.sa_sigaction = handle_signal;
    sigaction(SIGUSR1, &sa1, NULL);
    sa2.sa_flags = SA_SIGINFO;
    sa2.sa_sigaction = handle_signal;
    sigaction(SIGUSR2, &sa2, NULL);
    return (0);
}