/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_execve_module.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:34:52 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/01 15:35:03 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// check if the command available -> split path by : check that the file is binary one and access rights;
// validation -> no path / no such binary;
// if not ./ <-> current minishell;

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

int		check_dir_for_binary(char *path, char *binary_name)
{
	DIR *dir;
	struct dirent *dp;

	if ((dir = opendir (path)) == NULL) 
	 {
		perror ("Cannot open .");
		exit (1);
	}

	while ((dp = readdir (dir)) != NULL) 
	{
		if (ft_strequ(dp->d_name, binary_name))
		{
			closedir(dir);
			return (1);
		}
		
	}
	closedir(dir);
	return (0);
}

char	*find_dir_path(char *binary_name, char **path_list)
{
	int		i;
	char 	*path;

	i = 0;
	path = NULL;
	while (path_list[i])
	{
		if (check_dir_for_binary(path_list[i], binary_name))
		{
			// ft_printf("--------- yeah ----------- \n");
			path = ft_strdup(path_list[i]);
			// ft_printf("path -> %s\n", path);
			return (path);
		}
		i++;
	}
	return (path);
}

char	*find_binary_path(char *binary_name,  char **env_array)
{
	int		index;
	char	**path_list;
	char 	*buf;
	char 	*full_binary;

	full_binary = NULL;
	index = find_env_path(env_array);
	path_list = ft_strsplit(env_array[index], ':');
	buf = ft_strdup(path_list[0]);
	free(path_list[0]);
	path_list[0] = ft_strdup(&buf[5]);
	full_binary = find_dir_path(binary_name, path_list);
	ft_strcat(full_binary, "/");
	ft_strcat(full_binary, binary_name);
	ft_clean_2d_char(path_list);
	free(buf);
	return (full_binary);
}

void run_buitin_cmd(char **env_array) // binary name = first | flags = all with - prefix and remaining
{
	char *binary = find_binary_path("ls", env_array);

	if (binary == NULL)
		ft_printf("No such file\n");
	
	pid_t pid, wpid;
	int status;
	pid = fork();
	char* argv[] = { binary, "-laG", NULL };
	if (pid == 0) // Child process
	{
		if (execve(argv[0], argv, env_array) == -1) 
		{
	   		perror("lsh");
		}
	 	exit(EXIT_FAILURE);
   } 
   else if (pid < 0) 	 // Error forking
   {
		perror("lsh");
   } 
   else 	  // Parent process
   {
		// do
		// {
	   		wpid = waitpid(pid, &status, WUNTRACED);
			free(binary);
		// } 
	 // 	while (!WIFEXITED(status) && !WIFSIGNALED(status));
   }
}