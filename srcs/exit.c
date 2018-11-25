/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:57:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/25 13:32:37 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_minishell(char **envp)
{
	ft_clean_2d_char(envp);
	exit(0);
}
