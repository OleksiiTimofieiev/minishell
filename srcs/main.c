/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:35:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/08 21:40:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// TODO: norminette (rename funcs to static) & leaks

// TODO: $...$... -> echo, setenv, cd;

// TODO: quotes "" ''

// TODO: In cases where the executable cannot be found, it has to show an error message and
// display the prompt again.

	int
	detect_del_var_main(char *env, char **haystack)
{
	int i;
	int len_of_env;

	i = 0;
	len_of_env = ft_strlen(env);
	while (haystack[i])
	{
		if (ft_strncmp(env, haystack[i], len_of_env) == 0) //
		{
			if (haystack[i][len_of_env] == '=')
				return (i);
		}
		i++;
	}
	return ('x');
}

char	**check(char **envp_buf)
{
	if (detect_del_var_main("OLDPWD", envp_buf) == 'x')
		envp_buf = setenv_minishell("setenv OLDPWD /Users/otimofie 1", envp_buf);
	else if (detect_del_var_main("PWD", envp_buf) == 'x')
		envp_buf = setenv_minishell("setenv PWD /Users/otimofie 1", envp_buf);
	else if (detect_del_var_main("HOME", envp_buf) == 'x') // wtf ?
	{
		// ft_putstr("No home\n");
		envp_buf = setenv_minishell("setenv HOME /Users/otimofie 1", envp_buf);
	}
	return (envp_buf);
	
}

int		ft_quantity_of_chars(char *line, char c)
{
	int i;
	int quantity;

	i = 0;
	quantity = 0;
	while (line[i])
	{
		if (line[i] == c)
			quantity++;
		i++;
	}
	return (quantity);
}

void	change_to_spaces(char *str)
{
	while (*str)
	{
		if (*str == '\t')
			*str = ' ';
		str++;
	}
}

void 	minishell(char **envp_in)
{
	char	*line;
	char	**envp_buf;
	int		len_env_vars;
	char 	**cmd_array;

	line = NULL;
	cmd_array = NULL;
	// ft_printf("%s%s%s", CYAN , "1\n", RESET);
	envp_buf = init_envp_buf(envp_in);
	// ft_printf("%s%s%s", CYAN, "2\n", RESET);
	len_env_vars = ft_2d_arr_size(envp_buf) - 1;
	// ft_printf("%s%s%s", CYAN, "3\n", RESET);

	while (1)
	{
		envp_buf = check(envp_buf);	

		// len_env_vars = ft_2d_arr_size(envp_buf) - 1;

		ft_printf("%s%s%s", GREEN, "$> ", RESET);
		if (!(get_next_line(0, &line)))
			exit (0);

		change_to_spaces(line);

		if (ft_quantity_of_chars(line,';') >= 2)
		{
			ft_printf("We have some multiple instructions\r\n");
			cmd_array = ft_strsplit(line, ';');
		}
		else
		{
			cmd_array = (char **)malloc(sizeof(char *) * 2);
			cmd_array[1] = NULL;
			cmd_array[0] = ft_strdup(line);
		}
		// len_env_vars = ft_2d_arr_size(envp_buf) - 1;

		int i;

		i = 0;

		while (cmd_array[i])
		{
			if (!ft_strncmp(cmd_array[i], "cd", 2))
				cd(cmd_array[i], envp_buf);
			else if (!ft_strncmp(cmd_array[i], "echo", 4))
				echo(cmd_array[i], envp_buf);
			else if (ft_strequ(cmd_array[i], "env"))
				env_minishell(envp_buf);
			else if (!ft_strncmp(cmd_array[i], "exit", 4))
				exit_minishell(envp_buf);
			else if (!ft_strncmp(cmd_array[i], "setenv", 6))
				envp_buf = setenv_minishell(cmd_array[i], envp_buf);
			else if (!ft_strncmp(cmd_array[i], "unsetenv", 8))
				envp_buf = unsetenv_minishell(cmd_array[i], envp_buf);
			else
			{
				// ft_printf("%s%s%s", CYAN, "4\n", RESET);
				run_buitin_cmd(cmd_array[i], envp_buf);
				// ft_printf("%s%s%s", CYAN, "5\n", RESET);
			}
			i++;
		}
		(line) ? free(line) : 0;
		
		(cmd_array != NULL) ? ft_clean_2d_char(cmd_array) : 0;
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
