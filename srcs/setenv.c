/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:20:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/25 18:49:19 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_index_envp(char **envp_fuck, char *name)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp_fuck[i])
	{
		if (ft_strncmp(envp_fuck[i], name, len) == 0)
			return (i);
		i++;
	}
	return (0);
}

char	**get_buf_envp(char **arguments, char **envp_init)
{
	int		i;
	int		len;
	char	**buf;

	i = 0;
	len = len_char_2d_array(envp_init) + 2;
	buf = (char **)malloc(sizeof(char *) * (len));
	while (envp_init[i])
	{
		buf[i] = ft_strdup(envp_init[i]);
		i++;
	}
	buf[i] = ft_strdup(arguments[1]);
	ft_strcat(buf[i], "=");
	ft_strcat(buf[i++], arguments[2]);
	buf[i] = NULL;
	return (buf);
}

// char	**realloc_envp(char **buf)
// {
// 	int i;
// 	int len;
// 	char **realloc_envp;
// 	i = 0;
// 	len = len_char_2d_array(buf) + 1;
// 	realloc_envp = (char **)malloc(sizeof(char *) * len);
// 	while (buf[i])
// 	{
// 		realloc_envp[i] = ft_strdup(buf[i]);
// 		i++;
// 	}
// 	realloc_envp[i] = NULL;
// 	return (realloc_envp);
// }

int		setenv_minishell(char *str, char **envp_init)
{
	int		i;
	char	**arguments =NULL;
	int		len;
	char	**envp_buf = NULL;

	arguments = ft_strsplit(str, 32);

i = 0;
while (envp_init[i])
{
	ft_printf("%s\n", envp_init[i++]);
}
	i = 0;
	len = len_char_2d_array(arguments);
	if (len != 4)
	{
		ft_clean_2d_char(arguments);
		return (0);
	}
	i = get_index_envp(envp_init, arguments[1]);
	if (i)
	{
		ft_printf("%s%s%s\n", CYAN, "here1", RESET);
		if (ft_strequ(arguments[3], "1"))
		{
			free(envp_init[i]);
			envp_init[i] = ft_strdup(arguments[1]);
			ft_strcat(envp_init[i], "=");
			ft_strcat(envp_init[i], arguments[2]);
		}
	}
	else
	{
		ft_printf("%s%s%s\n", CYAN, "here2", RESET);
	
		envp_buf = get_buf_envp(arguments, envp_init);
		i = 0;
		while (envp_buf[i])
		{
			ft_printf("%s\n", envp_buf[i++]);
		}

		ft_clean_2d_char(envp_init);
		// envp = NULL;
		// envp = realloc_envp(envp_buf);
	
		i = 0;
		len = len_char_2d_array(envp_buf) + 1;
		if (!(envp_init = (char **)malloc(sizeof(char *) * len)))
		{
			ft_printf("WTF ?\n");
			return (0);
		}
		while (envp_buf[i])
		{
			envp_init[i] = ft_strdup(envp_buf[i]);
			i++;
		}
		envp_init[i] = NULL;
		ft_clean_2d_char(envp_buf);

		ft_printf("%s%s%s\n", CYAN, "here3", RESET);

		// ft_printf("%s%s%s\n", CYAN, "here3", RESET);
	}
	// ft_clean_2d_char(envp_init);

	ft_clean_2d_char(arguments);
	return (0);
}
