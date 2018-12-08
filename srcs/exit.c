/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:57:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/08 16:39:34 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_minishell(char **envp)
{
	if (**envp)
		ft_clean_2d_char(envp);
	// ft_printf("%s%s%s\n", CYAN, "WTF?2", RESET);
	system("leaks -q minishell");
	exit(0);
}
