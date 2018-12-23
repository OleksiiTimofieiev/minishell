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

// TODO: leaks and norminette in all folders;

// TODO: handle of "" and ''; noy 0 or % 0

// TODO: main infrastructure;

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

void	execution_cycle(t_env *env, char **cmd_array)
{
	int i;
	int j;

	i = 0;
	while (cmd_array[i])
	{
		check_special_env(env);
		j = detect_not_space(cmd_array[i]);
		if (!ft_strncmp(&cmd_array[i][j], "cd", 2))
			cd(cmd_array[i], &env);
		else if (!ft_strncmp(&cmd_array[i][j], "echo", 4))
			echo(cmd_array[i], &env);
		else if (ft_strequ(&cmd_array[i][j], "env"))
			env_minishell(env);
		else if (!ft_strncmp(&cmd_array[i][j], "exit", 4))
			exit_minishell(&env);
		else if (!ft_strncmp(&cmd_array[i][j], "setenv", 6))
			setenv_minishell(cmd_array[i], env);
		else if (!ft_strncmp(&cmd_array[i][j], "unsetenv", 8))
			unsetenv_minishell(cmd_array[i], env);
		else
			run_buitin_cmd(&cmd_array[i][j], env);
		i++;
	}
}

char	**cmd_array_constructor(char *line)
{
		char **cmd_array;

		change_to_spaces(line, '\t', ' ');

		if (ft_quantity_of_chars(line, ';'))
			cmd_array = ft_strsplit(line, ';');
		else
		{
			cmd_array = (char **)malloc(sizeof(char *) * 2);
			cmd_array[0] = ft_strdup(line);
			cmd_array[1] = NULL;
		}
		return (cmd_array);
}

void	minishell(void)
{
	char	*line;
	char	**cmd_array;
	t_env	*env;
	
	env = NULL;
	cmd_array = NULL;
	signal(SIGINT, signal_handler);
	init_env(&env);
	if (!env)
	{
		ft_printf("%s%s\n%s", RED, "no env vars.", RESET);
		exit(0);
	}
	while (1)
	{
		ft_printf("%s%s%s", GREEN, "$> ", RESET);
		if (!(get_next_line(0, &line)))
			exit(0);
		cmd_array = cmd_array_constructor(line);
		execution_cycle(env, cmd_array);
		(line) ? free(line) : 0;
		(cmd_array != NULL) ? ft_clean_2d_char(cmd_array) : 0;
		system("leaks -q minishell");
	}
}

int		main(void)
{
	minishell();
	return (0);
}
