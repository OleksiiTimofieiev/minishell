#include "../includes/minishell.h"

// use array of functions for echo, ...
// work with ./ and maybe without it
// You must manage expansions $ and  ̃

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	echo("echo test1 test2 test3 test4 $Path", envp);

	// while get_next_line

	system("leaks -q minishell");
	return 0;
}

