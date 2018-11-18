#include "../includes/minishell.h"

// use array of functions for echo, ...
// work with ./ and maybe without it
// You must manage expansions $ and  ̃
// // int		check_till_equal $f case

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	echo("echo sdf sd $ ~", envp);

	// while get_next_line

	system("leaks -q minishell");
	return 0;
}

