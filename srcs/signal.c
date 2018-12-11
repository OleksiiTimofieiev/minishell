#include "../includes/minishell.h"

void	signal_handler(int sig_num)
{
    /*do something*/
    // ft_printf("Magic... moments... %d\n", getpid());
    sig_num = 'c';
    // exit(0);signal(SIGINT, signal_handler);
    signal(SIGINT, signal_handler);
}