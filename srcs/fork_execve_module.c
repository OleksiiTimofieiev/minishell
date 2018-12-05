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

// find in PATH variable;
// check if the command available -> split path by : check that the file is binary one and access rights;
// if available ->strdup

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

void	find_binary_path(/*char *binary, */ char **env_array)
{
	int		index;
	char	**path_list;
	char 	*buf;

	index = find_env_path(env_array);
	path_list = ft_strsplit(env_array[index], ':');

	buf = ft_strdup(path_list[0]);
	free(path_list[0]);

	path_list[0] = ft_strdup(&buf[5]);

	int i = 0;
	while (path_list[i])
	{
		ft_printf("%s\n", path_list[i]);
		i++;
	}

	ft_clean_2d_char(path_list);
	free(buf);

}

int lsh_launch(char **env_array)
{
	find_binary_path(env_array);
//    pid_t pid, wpid;
//    int status;
//    pid = fork();
//    char* argv[] = { "/bin/ls", "-l", "-a", "-G", ".", NULL };
//    if (pid == 0) {
//      // Child process
//      if (execve(argv[0], argv, env_array) == -1) {
//        perror("lsh");
// }
//      exit(EXIT_FAILURE);
//    } else if (pid < 0) {
//      // Error forking
//      perror("lsh");
//    } else {
 
//       // Parent process
//      do {
//        wpid = waitpid(pid, &status, WUNTRACED);
//      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
//    }
// 	return 1; 
	return (0);
}