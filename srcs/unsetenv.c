/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:52:16 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/25 14:10:57 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_node(t_env **head_ref, char *name)
{
	t_env *temp;
	t_env *prev;

	temp = *head_ref;
	if (temp != NULL && ft_strcmp(temp->name, name) == 0)
	{
		*head_ref = temp->next;
		free(temp->name);
		free(temp->content);
		free(temp);
		return ;
	}
	while (temp != NULL && ft_strcmp(temp->name, name) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp->name);
	free(temp->content);
	free(temp);
}

void	unsetenv_minishell(char *str, t_env *env)
{
	t_env	*env_local;
	char	**arguments;

	arguments = ft_strsplit(str, 32);
	if (len_char_2d_array(arguments) != 2)
	{
		ft_printf("%s%s%s", RED,
		"Wrong number of arguments -> has to be 1\n", RESET);
		return ;
	}
	env_local = find_elem(&env, arguments[1]);
	if (env_local)
		delete_node(&env, env_local->name);
	(arguments) ? ft_clean_2d_char(arguments) : 0;
}
