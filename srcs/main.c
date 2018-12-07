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
// TODO: validation for setenv (quantity of arguments, 1 or 0) if no 3 argument, defaul == 0;
// TODO: work out when there is no such env var in unsetenv
// TODO: unsetenv value is not in the env list, NAME=Value format, arguments is more then 2;
// TODO: echo "" || '', errors -> replace with spaces " symbol;
// TODO: detect missing '' || ""

void	minishell(char *line, char **envp_buf)
{
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
		// else
		// 	run_buitin_cmd(envp_buf);
		free(line);
		
		system("leaks -q minishell");
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char *line;
	char **envp_buf;

	line = NULL;
	envp_buf = init_envp_buf(envp);
	minishell(line, envp_buf);
	return (0);
}
