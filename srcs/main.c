#include "../includes/minishell.h"

// use array of functions for echo, ...
// You must manage expansions $ and  ̃
// validation for setenv (quantity of arguments, 1 or 0)
// validation for main
// quotes -> dismiss quotes;
// getcwd as parameter to PWD;

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char *line;
	char **envp_buf;

	envp_buf = init_envp_buf(envp);

	while(1)
	{
		ft_printf("%s%s%s", GREEN, "$> ", RESET);

		get_next_line(0, &line);

		if (!ft_strncmp(line, "cd", 2))
			cd(line, envp_buf);
		else if (!ft_strncmp(line, "echo", 4))
			echo(line, envp_buf);
		else if (ft_strequ(line, "env"))
			env_minishell(envp_buf);
		else if (!ft_strncmp(line, "exit", 4))
			exit_minishell(envp_buf);
		else if (!ft_strncmp(line, "setenv", 6))
			envp_buf = setenv_minishell(line, envp_buf);
		system("leaks -q minishell");
		
		// else
			// ft_printf("%sminishell: command not found: %s%s\n", 
			// 	RED, line, RESET);
			// use fork;

		free(line);


	}
		
	return 0;
}
