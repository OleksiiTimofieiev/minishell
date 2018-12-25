/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:57:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 15:26:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void  delete_list(t_env** head_ref) 
{ 
   t_env *current = *head_ref; 
   t_env *next; 
  
   while (current != NULL)  
   { 
       next = current->next;
       free(current->name);
       free(current->content);
       free(current); 
       current = next; 
   } 
   *head_ref = NULL; 
} 

void  exit_minishell(t_env **env)
{
	if (env)
		delete_list(env);
	system("leaks -q minishell");
	exit(0);
}
