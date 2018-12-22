/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_execve_module.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:34:52 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 15:43:40 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_buitin_cmd_helper(char *binary, char **argument, char **env_array)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	signal(SIGINT, signal_handler);
	if (pid == 0)
	{
		if (execve(binary, argument, env_array) == -1)
		{
			ft_printf("%s%s%s", RED, "No such binary\n", RESET);
			ft_clean_2d_char(argument);
			free(binary);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		ft_printf("%s%s%s", RED, "Error with fork func.\n", RESET);
	else
	{
		wpid = waitpid(pid, &status, 0);
		free(binary);
		ft_clean_2d_char(argument);
	}
}

void	run_buitin_cmd(char *line, char **env_array)
{
	char	**argument;
	char	*binary;

	argument = ft_strsplit(line, 32);
	if (!env_array[0])
	{
		ft_printf("%s%s%s", RED, "No env variables.\n", RESET);
		exit(0);
	}
	binary = find_binary_path(argument[0], env_array);
	if (binary == NULL && argument[0])
		binary = ft_strdup(argument[0]);
	run_buitin_cmd_helper(binary, argument, env_array);
}
