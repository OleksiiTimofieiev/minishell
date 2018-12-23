/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:52:16 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 16:12:49 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete_node(t_env **head_ref, char *name) 
{ 
    // Store head node 
    t_env* temp = *head_ref;
    t_env *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && ft_strcmp(temp->name, name) == 0) 
    { 
        *head_ref = temp->next;   // Changed head 
          	free(temp->name);
  	free(temp->content);
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && ft_strcmp(temp->name, name) != 0) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
  	free(temp->name);
  	free(temp->content);
    free(temp);  // Free memory 
} 

void	unsetenv_minishell(char *str, t_env *env)
{
	t_env	*env_local;
	char	**arguments;

	arguments = ft_strsplit(str, 32);
	if (len_char_2d_array(arguments) != 2)
	{
		ft_printf("%s%s%s", RED,
		"Wrong number of arguments -> has to be 1\n", RESET);
		return ;
	}
	env_local = find_elem(&env, arguments[1]);
	if (env_local)
		delete_node(&env, env_local->name);
	(arguments) ? ft_clean_2d_char(arguments) : 0;
}
