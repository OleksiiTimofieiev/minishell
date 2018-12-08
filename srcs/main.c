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


// TODO: norminette (rename funcs to static) & leaks

// TODO: add var if $ or ~ to the line, rethink the funcs;

// bonus: Management of execution rights in the PATH, ; stuff;

void	minishell(char **envp_in)
{
	char	*line;
	char	**envp_buf;
	int		len_env_vars;

	line = NULL;
	envp_buf = init_envp_buf(envp_in);
	len_env_vars = ft_2d_arr_size(envp_buf) - 1;
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
			envp_buf = unsetenv_minishell(line, envp_buf, len_env_vars);
		else
			run_buitin_cmd(line, envp_buf);
		(line) ? free(line) : 0;
		system("leaks -q minishell");
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	minishell(envp);
	return (0);
}
