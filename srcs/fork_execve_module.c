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

void	run_buitin_cmd_helper(char *binary, char **argument, char **env_vars)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	signal(SIGINT, signal_handler);
	if (pid == 0)
	{
		if (execve(binary, argument, env_vars) == -1)
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

int		len_of_list(t_env *env)
{
	int i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char 	**env_vars_array(t_env *env)
{
	int		i;
	int		len;
	char 	**result;

	i= 0;
	len = len_of_list(env);
	result = (char **)malloc(sizeof(char *) * (len + 1));

	while (env)
	{
		result[i] = ft_strnew(ft_strlen(env->name)+ 1+ ft_strlen(env->content));
		ft_strcat(result[i], env->name);
		ft_strcat(result[i], "=");
		ft_strcat(result[i], env->content);
		i++;
		env = env->next;
	}
	result[i] = NULL;
	return(result);
}

void	mod_flags(char **arguments, t_env *env)
{
	int i;

	i = 0;
	while (arguments[i])
		special_char_fork(&arguments[i++], env);
}

void	run_buitin_cmd(char *line, t_env *env)
{
	char	**arguments;
	char	*binary;
	char 	**env_vars;

	env_vars = env_vars_array(env);
	arguments = ft_strsplit(line, 32);
	mod_flags(arguments, env);
	// $pwd and tilda...
	binary = find_binary_path(arguments[0], &env);
	if (binary == NULL && arguments[0])
		binary = ft_strdup(arguments[0]);
	run_buitin_cmd_helper(binary, arguments, env_vars);
	ft_clean_2d_char(env_vars);
}
