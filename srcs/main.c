/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:35:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 17:58:17 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	**check(char **envp_buf)
// {
// 	if (detect_del_var("OLDPWD", envp_buf) == 'x')
// 		envp_buf = setenv_minishell("setenv OLDPWD /Users/otimofie 1",
// 		envp_buf);
// 	if (detect_del_var("PWD", envp_buf) == 'x')
// 		envp_buf = setenv_minishell("setenv PWD /Users/otimofie 1", envp_buf);
// 	if (detect_del_var("HOME", envp_buf) == 'x')
// 		envp_buf = setenv_minishell("setenv HOME /Users/otimofie 1", envp_buf);
// 	return (envp_buf);
// }

// remaster main, cd, echo, env, exit, fork;

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

void	change_to_spaces(char *str, char find, char required)
{
	while (*str)
	{
		if (*str == find)
			*str = required;
		str++;
	}
}

int		detect_not_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32)
			return (i);
		i++;
	}
	return (i);
}

char	**test_x(char *str, int j, char **envp_buf)
{
	char **test;
	// char **buf = NULL;

	test = envp_buf;
	if (!ft_strncmp(&str[j], "cd", 2))
		cd(str, envp_buf);
	else if (!ft_strncmp(&str[j], "echo", 4))
		echo(str, envp_buf);
	else if (ft_strequ(&str[j], "env"))
		env_minishell(envp_buf);
	else if (!ft_strncmp(&str[j], "exit", 4))
		exit_minishell(envp_buf);
	else if (!ft_strncmp(&str[j], "setenv", 6))
	{
			test = setenv_minishell(str, envp_buf);
			// test = buf;
	}
	// else if (!ft_strncmp(&str[j], "unsetenv", 8))
	// {
	// 	envp_buf = unsetenv_minishell(str, envp_buf);
	// 	envp_buf = check(envp_buf);
	// }
	else
		run_buitin_cmd(&str[j], envp_buf);
	return (test);
}

char	**ex(char	**cmd_array, char	**envp_buf)
{
	int i;
	int		j;

	char **test = envp_buf;
	char **buf = NULL;

		i = 0;

		while (cmd_array[i])
		{
			j = detect_not_space(cmd_array[i]);

			buf = test_x(cmd_array[i], j, envp_buf);

			// (buf != envp_buf) ? ft_clean_2d_char(envp_buf) : 0;

			test = buf;


			i++;
		}
		return (test);
}

void	minishell(char **envp_in)
{
	char	*line;
	char	**envp_buf;
	// int		len_env_vars;
	char	**cmd_array;
	char 	**env_copy= NULL;
	

	line = NULL;
	cmd_array = NULL;
	envp_buf = copy_2d_char(envp_in);
	// len_env_vars = ft_2d_arr_size(envp_buf) - 1;
	char **buf = NULL;

	while (1)
	{
		// envp_buf = check(envp_buf);
		ft_printf("%s%s%s", GREEN, "$> ", RESET);
		if (!(get_next_line(0, &line)))
			exit(0);

		change_to_spaces(line, '\t', ' ');

		if (ft_quantity_of_chars(line, ';'))
		{
			ft_printf("We have some multiple instructions\r\n");
			cmd_array = ft_strsplit(line, ';');
		}
		else
		{
			cmd_array = (char **)malloc(sizeof(char *) * 2);
			cmd_array[0] = ft_strdup(line);
			cmd_array[1] = NULL;
		}

		//
		(buf != NULL) ? ft_clean_2d_char(buf) : 0;
		(env_copy != NULL) ? ft_clean_2d_char(env_copy) : 0;

		ft_printf("%s%s\n%s", CYAN, "here", RESET);

		env_copy = copy_2d_char(envp_buf);
		buf = ex(cmd_array, env_copy);
		
		
		// if (envp_buf)

		// ft_clean_2d_char(envp_buf);

		envp_buf = copy_2d_char(buf);

		(line) ? free(line) : 0;
		(cmd_array != NULL) ? ft_clean_2d_char(cmd_array) : 0;
		system("leaks -q minishell");
	}
}

int		main(int argc, char **argv, char **envp)
{
	signal(SIGINT, signal_handler);
	(void)argc;
	(void)argv;
	minishell(envp);
	return (0);
}
