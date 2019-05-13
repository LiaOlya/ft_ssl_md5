/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:38:03 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/01 20:38:04 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *temp;

	if (alst && del)
	{
		temp = *alst;
		while (temp != NULL)
		{
			*alst = temp;
			temp = temp->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
		}
	}
}
