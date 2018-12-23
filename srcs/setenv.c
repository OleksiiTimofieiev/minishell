/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:20:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 18:03:02 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		find_char_setenv(char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = i;
			return (j);
		}
		i++;
	}
	return (j);
}

int		special_char_occurance(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '$')
			i++;
		str++;
	}
	return (i);
}

void	not_available(char **arguments, t_env *head)
{
	t_env   *new;

    new = (t_env *)malloc(sizeof(t_env));
    new->name = strdup(arguments[1]);
    new->content = strdup(arguments[2]);
    new->next = NULL;

    while (head->next)
        head = head->next;
    head->next = new;
}

void	env_available(char **arguments, t_env *env)
{
	if (ft_strequ(arguments[3], "1"))
	{
		free((env)->content);
		(env)->content = ft_strnew(ft_strlen(arguments[2]));
		ft_memset((env)->content, 0x0, ft_strlen(arguments[2]));
		ft_strcat((env)->content, arguments[2]);
	}
}

void	tilda_setenv(char **arguments)
{
	char *result;

	if (arguments[2][0] == '~' && arguments[2][1] == '/')
	{
		result = ft_strnew(ft_strlen("/Users/otimofie") + ft_strlen(&arguments[2][1]));
		ft_strcat(result, "/Users/otimofie");
		ft_strcat(result, &arguments[2][1]);
		free(arguments[2]);
		arguments[2] = ft_strdup(result);
		free(result);
	}
}

void	woohoo_help_setenv(char **path, char *env_value, char *str, int j)
{
	*path = ft_strnew(ft_strlen(env_value) + 1 + ft_strlen(&str[j + 1]));
	ft_strcat(*path, env_value);
	ft_strcat(*path, "/");
	ft_strcat(*path, &str[j + 1]);
}

char 	*woohoo_setenv(char *str, t_env **env)
{
	int		j;
	char	*path;
	char	*env_value;
	char	*buf;
	t_env	*test;

	path = NULL;
	env_value = NULL;
	buf = NULL;
	j = find_char_setenv(str, '/');
	if (j)
	{
		str[j] = '\0';
		buf = ft_strdup(&str[1]);
		test = find_elem(env, buf);
		if (test)
			env_value = ft_strdup(find_elem(env, buf)->content);
		if (env_value)
		{
			woohoo_help_setenv(&path, env_value, str, j);
		}
	}
	(env_value) ? free(env_value) : 0;
	(buf) ? free(buf) : 0;
	return (path);
}

void	special_char_help(char **arguments, t_env *env)
{
	char	*slash;
	char 	*buf;
	char    *copy;

	slash = NULL;
	buf = NULL;
	copy = ft_strdup(arguments[2]);
	buf = woohoo_setenv(copy, &env);
	if (buf)
		slash = ft_strdup(buf);
	if (slash)
	{
		free(arguments[2]);
		arguments[2] = ft_strdup(slash);
	}	
	(copy) ? free(copy) : 0;
	(buf) ? free(buf) : 0;
	(slash) ? free(slash) : 0;
}

void	special_char(char **arguments, t_env *env)
{
	t_env	*env_local;

	if (arguments[2][0] == '$' && special_char_occurance(arguments[2]) == 1)
	{
		if (!find_char_setenv(arguments[2], '/'))
		{
			env_local = find_elem(&env, &arguments[2][1]);
			if (env_local)
			{
				free(arguments[2]);
				arguments[2] = ft_strdup(env_local->content);
			}
		}
		else
		{
			special_char_help(arguments, env);
		}
	}
}

void	setenv_minishell(char *str, t_env *env)
{
	char	**arguments;
	int		q_params;
	t_env	*env_var;

	arguments = ft_strsplit(str, 32);
	q_params = len_char_2d_array(arguments);
	if (q_params < 3 || q_params > 4)
	{
		ft_clean_2d_char(arguments);
		return ;
	}
	tilda_setenv(arguments);
	special_char(arguments, env);

	env_var = find_elem(&env, arguments[1]);

	if (env_var)
		env_available(arguments, env_var);
	else
		not_available(arguments, env);


	(arguments) ? ft_clean_2d_char(arguments) : 0;
	
}
