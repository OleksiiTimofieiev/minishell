#include "../includes/minishell.h"

// use array of functions for echo, ...

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	echo("echo test1 test2 test3 test4 $", envp);

	system("leaks -q minishell");
	return 0;
}

