/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:13:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/25 13:16:17 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_minishell(t_env *env)
{
    while (env)
    {
        ft_printf("%s=%s\n", env->name, env->content);
        env = env->next;
    }  
}
