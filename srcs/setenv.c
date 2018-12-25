/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:20:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/25 14:02:33 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	not_available(char **arguments, t_env *head)
{
	t_env	*new;

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
		result = ft_strnew(ft_strlen("/Users/otimofie") +
			ft_strlen(&arguments[2][1]));
		ft_strcat(result, "/Users/otimofie");
		ft_strcat(result, &arguments[2][1]);
		free(arguments[2]);
		arguments[2] = ft_strdup(result);
		free(result);
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
