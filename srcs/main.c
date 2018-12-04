/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:35:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/01 15:35:07 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#include <stdio.h>

// TODO: norminette & leaks
// TODO: You must manage expansions $ and  ̃
// TODO: validation for setenv (quantity of arguments, 1 or 0)
// TODO: validation for main
// TODO: quotes -> dismiss quotes;
// TODO: maybe: cfunc to detect the type of the comd (if true -> continue);
// TODO: work out when there is no such env var in unsetenv
// TODO: unsetenv value is not in the env list , NAME=Value format, arguments is more then 2;
// TODO: try getcwd with cd to get more cool cd

// check if the command available -> split path by : check that the file is binary one and access rights;
// if available ->strdup
int lsh_launch(char **env_array)
{
   pid_t pid, wpid;
   int status;
   pid = fork();
   char* argv[] = { "/bin/ls", "-l", "-a", "-G", ".", NULL };
   if (pid == 0) {
     // Child process
     if (execve(argv[0], argv, env_array) == -1) {
       perror("lsh");
}
     exit(EXIT_FAILURE);
   } else if (pid < 0) {
     // Error forking
     perror("lsh");
   } else {
 
      // Parent process
     do {
       wpid = waitpid(pid, &status, WUNTRACED);
     } while (!WIFEXITED(status) && !WIFSIGNALED(status));
   }
return 1; }

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char *line;
	char **envp_buf;

	envp_buf = init_envp_buf(envp);

	while (1)
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
		else if (!ft_strncmp(line, "unsetenv", 8))
			envp_buf = unsetenv_minishell(line, envp_buf);

		lsh_launch(envp);
		system("leaks -q minishell");

		
		// else
			// ft_printf("%sminishell: command not found: %s%s\n", 
			// 	RED, line, RESET);
			// use fork;

		free(line);


	}
		
	return 0;
}
