/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_execve_module_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:43:43 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 15:47:11 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		find_env_path(char **env_array)
{
	int i;

	i = 0;
	while (env_array[i])
	{
		if (ft_strncmp("PATH", env_array[i], 4) == 0)
			return (i);
		i++;
	}
	return (0);
}

int		check_modes(char *path_buf, DIR *dir)
{
	struct stat buf;

	if (access(path_buf, F_OK) == -1)
	{
		return (0);
	}
	lstat(path_buf, &buf);
	if (buf.st_mode & S_IXUSR)
	{
		closedir(dir);
		return (1);
	}
	else
	{
		ft_printf("%s%s%s", RED, "No execution rights.\n", RESET);
		closedir(dir);
		return (0);
	}
	return (7);
}

int		check_dir_for_binary(char *path, char *binary_name)
{
	DIR				*dir;
	struct dirent	*dp;
	int				check;
	char			path_buf[1024];

	ft_memset(path_buf, 0x0, sizeof(path_buf));
	if ((dir = opendir(path)) == NULL)
		return (0);
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_strequ(dp->d_name, binary_name))
		{
			ft_strcat(path_buf, path);
			ft_strcat(path_buf, "/");
			ft_strcat(path_buf, dp->d_name);
			check = check_modes(path_buf, dir);
			if (check != 7)
				return (check);
		}
	}
	closedir(dir);
	return (0);
}

char	*find_dir_path(char *binary_name, char **path_list)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (path_list[i])
	{
		if (check_dir_for_binary(path_list[i], binary_name))
		{
			path = ft_strdup(path_list[i]);
			return (path);
		}
		i++;
	}
	return (path);
}

char	*find_binary_path(char *binary_name, char **env_array)
{
	int		index;
	char	**path_list;
	char	*buf;
	char	*full_binary;
	char	*result;

	index = find_env_path(env_array);
	path_list = ft_strsplit(env_array[index], ':');
	buf = ft_strdup(path_list[0]);
	free(path_list[0]);
	path_list[0] = ft_strdup(&buf[5]);
	if (!(full_binary = find_dir_path(binary_name, path_list)))
	{
		ft_clean_2d_char(path_list);
		free(buf);
		return (full_binary);
	}
	result = ft_strnew(ft_strlen(full_binary) + 1 + ft_strlen(binary_name));
	ft_strcat(result, full_binary);
	ft_strcat(result, "/");
	ft_strcat(result, binary_name);
	ft_clean_2d_char(path_list);
	free(buf);
	free(full_binary);
	return (result);
}