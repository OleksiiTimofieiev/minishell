/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:35:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/08 18:52:21 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// TODO: norminette (rename funcs to static) & leaks

// TODO: add var if $ or ~ to the line, rethink the funcs;

// TODO: quotes "" ''

int detect_del_var_main(char *env, char **haystack)
{
	int i;
	int len_of_env;

	i = 0;
	len_of_env = ft_strlen(env);
	while (haystack[i])
	{
		if (ft_strncmp(env, haystack[i], len_of_env) == 0 && haystack[i][len_of_env] == '=') //
			return (i);
		i++;
	}
	return ('x');
}


void	minishell(char **envp_in)
{
	char	*line;
	char	**envp_buf;
	int		len_env_vars;

	line = NULL;
	// ft_printf("%s%s%s", CYAN , "1\n", RESET);
	envp_buf = init_envp_buf(envp_in);
	// ft_printf("%s%s%s", CYAN, "2\n", RESET);

	len_env_vars = ft_2d_arr_size(envp_buf) - 1;
	// ft_printf("%s%s%s", CYAN, "3\n", RESET);

	while (1)
	{
		if (detect_del_var_main("OLDPWD", envp_buf) == 'x')
			envp_buf = setenv_minishell("setenv OLDPWD /Users/otimofie 1", envp_buf);
		else if (detect_del_var_main("PWD", envp_buf) == 'x')
			envp_buf = setenv_minishell("setenv PWD /Users/otimofie 1", envp_buf);
		// else if (detect_del_var_main("HOME", envp_buf) == 'x') / wtf ?
		// 	envp_buf = setenv_minishell("setenv HOME /Users/otimofie 1", envp_buf);

		len_env_vars = ft_2d_arr_size(envp_buf) - 1;

		ft_printf("%s%s%s", GREEN, "$> ", RESET);
		if (!(get_next_line(0, &line)))
			exit (0);
		len_env_vars = ft_2d_arr_size(envp_buf) - 1;


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
		else
		{
			// ft_printf("%s%s%s", CYAN, "4\n", RESET);
			run_buitin_cmd(line, envp_buf);
			// ft_printf("%s%s%s", CYAN, "5\n", RESET);
		}
		(line) ? free(line) : 0;
		// system("leaks -q minishell");
	}
}

int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	minishell(envp);
	return (0);
}
