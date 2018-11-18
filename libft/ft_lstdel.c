/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:22:06 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/18 13:22:08 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *head;
	t_list *tmp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	head = *alst;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
	*alst = NULL;
}
