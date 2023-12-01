#include "minitalk.h"

int	ft_isdigit(int c)
{
	return ((c <= 57 && c >= 48));
}

void	decoder(pid_t pid ,unsigned char c)
{
	int				count;
	unsigned int	base;

	count = 7;
	base = 128;
	while (count >= 0)
	{
		if (c < base)//0
		{
			//kill(pid, SIGUSR1);
            // printf("\nIN IF\n");
            // printf("c:%d\n",c);
            // printf("b:%d\n",base);
            //printf("%d",0);
		}			
		else//1
		{
			//kill(pid, SIGUSR2);
			c = c - base;
            // printf("\nIN ELSE\n");
            // printf("c:%d\n",c);
            // printf("b:%d\n",base);
             //printf("%d",1);

		}
		base = base / 2;
		count--;
		usleep(100);
	}
}
int main(int argc,char *argv[])
{
    char    *msg;
    
    msg = argv[2];
    if (argc == 3)
	{
		//server_pid = ft_atoi(argv[1]);
		while (*msg)
		{
			decoder(0 ,*msg);
            printf("\n");
			//ft_putchar_cnt('\n');
			msg++;
		}
		decoder(0,'\0');
	}
    else if (argc != 3)//check format
    {
        printf("!! client [PID] [Message] !!");
        return (0);
    }

    

    return (0);
}

// h: 104  --> 01101000
// e: 101  --> 01100101
// l: 108  --> 01101100
// l: 108  --> 01101100
// o: 111  --> 01101111
