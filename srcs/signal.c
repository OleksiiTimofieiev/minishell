/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:09:25 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 16:09:42 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(int sig_num)
{
	(void)sig_num;
	system("clear");
	ft_printf("%sMagic... moments...%s\n", CYAN, RESET);
	ft_printf("%s%s%s", GREEN, "$> ", RESET);
	signal(SIGINT, signal_handler);
}
