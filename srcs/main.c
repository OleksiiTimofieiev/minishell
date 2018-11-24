#include "../includes/minishell.h"

// use array of functions for echo, ...
// You must manage expansions $ and  ̃
// // int		check_till_equal $f case

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char *line;
	
	while(get_next_line(0,&line))
	{
		if (ft_strstr(line, "cd"))
			cd(line, envp);
		else if (ft_strstr(line, "echo"))
			echo(line, envp);
		

		system("ls -laG $PWD");
		system("leaks -q minishell");
		
		free(line);
	}

	system("leaks -q minishell");
	return 0;
}

