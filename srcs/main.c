#include "../includes/minishell.h"

// use array of functions for echo, ...
// work with ./ and maybe without it
// You must manage expansions $ and  ̃
// // int		check_till_equal $f case

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;


	// echo("echo sdf sd $ ~", envp);
	char *line;
	
	while(get_next_line(0,&line))
	{
		if (ft_strstr(line, "cd"))
		{
			cd(line, envp);

			system("ls -laG $PWD");
			free(line);
			system("leaks -q minishell");
		}

	}

	system("leaks -q minishell");
	return 0;
}

