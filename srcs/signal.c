#include "../includes/minishell.h"

void	signal_handler(int sig_num)
{
    (void)sig_num;

    /*do something*/
    system("clear");
    ft_printf("%sMagic... moments...%s\n", CYAN, RESET);
    ft_printf("Please enter the command\n");
    // sig_num = 'c';
    // exit(0);signal(SIGINT, signal_handler);
    signal(SIGINT, signal_handler);
}