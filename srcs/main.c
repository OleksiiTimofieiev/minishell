#include "../includes/minishell.h"

// use array of functions for echo, ...
// You must manage expansions $ and  ̃
// // int		check_till_equal $f case


int		main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char *line;

	char **envp_buf;
	int len = len_char_2d_array(envp);

	// ft_printf("len -> %d\n", len);

	envp_buf = (char **)malloc(sizeof(char *) * (len + 1));

	int i = 0;
	
	while(envp[i])
	{
		envp_buf[i] = ft_strdup(envp[i]);
		i++;
	}

	// i = 0;
	// while (envp_buf[i])
	// {
	// 	ft_printf("%s\n", envp_buf[i]);
	// 	i++;
	// }

	envp_buf[len] = NULL;

	
	while(1)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		if (ft_strstr(line, "cd"))
			cd(line, envp_buf);
		else if (ft_strstr(line, "echo"))
			echo(line, envp_buf);

		// system("ls -laG $PWD");
		// system("leaks -q minishell");

		free(line);
		/* code */
	}
	
	// {
		
	// }

	system("leaks -q minishell");
	// ft_clean_2d_char(envp_buf);
	return 0;
}

