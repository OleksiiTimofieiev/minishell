/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_infrastructure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:52:03 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 15:29:11 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env   *find_elem(t_env **head, char *str)
{
	t_env *current = *head;
    while (current)
    {
        if (ft_strcmp( current->name, str) == 0)
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
