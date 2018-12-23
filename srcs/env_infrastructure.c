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
        if (ft_strcmp( (current)->name, str) == 0)
        {
        	// ft_putstr("asdf\n");
            return (current);
        }
        current = (current)->next;
    }
    return (NULL);
}

void	ft_clean(t_env **env)
{
	// t_env **path =(t_env **)malloc(sizeof(t_env *) * 2);

	t_env *path_x;
	t_env *path_y;


	path_x = find_elem(env, "PWD");
	path_y = find_elem(env, "OLDPWD");

			ft_printf("%s%s\n%s", CYAN, path_x->content, RESET);




	if (path_x->content != NULL)
	{
		free(path_x->content);
	}
	if (path_y->content != NULL)
		free(path_y->content);
	
	ft_printf("%s%s\n%s", CYAN, "6", RESET);
}


int		detect_del_var(char *env, char **haystack)
{
	int i;
	int len_of_env;

	i = 0;
	len_of_env = ft_strlen(env);
	while (haystack[i])
	{
		if (ft_strncmp(env, haystack[i], len_of_env) == 0)
		{
			if (haystack[i][len_of_env] == '=')
				return (i);
		}
		i++;
	}
	return ('x');
}
