/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_infrastructure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:52:03 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/25 13:55:08 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// extern	char **environ;

t_env	*find_elem(t_env **head, char *str)
{
	t_env *current;

	current = *head;
	while (current)
	{
		if (ft_strcmp(current->name, str) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	ft_clean(t_env **env)
{
	t_env *path_x;
	t_env *path_y;

	path_x = find_elem(env, "PWD");
	path_y = find_elem(env, "OLDPWD");
	if (path_x->content != NULL)
	{
		free(path_x->content);
	}
	if (path_y->content != NULL)
		free(path_y->content);
}

void	push_back(t_env **head, char *str)
{
	t_env	*new;
	t_env	*last;
	char	**split;

	split = ft_strsplit(str, '=');
	last = *head;
	new = (t_env *)malloc(sizeof(t_env));
	new->name = strdup(split[0]);
	new->content = strdup(split[1]);
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	ft_clean_2d_char(split);
}

void	init_env(char **envp, t_env **env)
{
	int i;

	i = 0;
	while (envp[i])
		push_back(env, envp[i++]);
}

void	check_special_env(t_env *env)
{
	t_env *tests;

	tests = find_elem(&env, "OLDPWD");
	if (!tests)
		setenv_minishell("setenv OLDPWD /Users/otimofie", env);
	tests = find_elem(&env, "PWD");
	if (!tests)
		setenv_minishell("setenv PWD /Users/otimofie", env);
	tests = find_elem(&env, "HOME");
	if (!tests)
		setenv_minishell("setenv HOME /Users/otimofie", env);
}
