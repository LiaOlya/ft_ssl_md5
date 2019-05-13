/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:34:15 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/09 13:34:16 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstaddend(t_list **lst, char *n)
{
	t_list *temp;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = (t_list*)malloc(sizeof(t_list));
		(*lst)->content = ft_strdup(n);
		(*lst)->next = NULL;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (t_list*)malloc(sizeof(t_list));
	temp->next->content = ft_strdup(n);
	temp->next->next = NULL;
}

