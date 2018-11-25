#include "../includes/minishell.h"

// use array of functions for echo, ...
// You must manage expansions $ and  ̃
// // int		check_till_equal $f case

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
			setenv_minishell(line, envp_buf);
		// else
			// ft_printf("%sminishell: command not found: %s%s\n", 
			// 	RED, line, RESET);
			// use fork;

		free(line);


	}
		
	return 0;
}
