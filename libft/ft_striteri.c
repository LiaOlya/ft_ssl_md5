/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:22:51 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:22:52 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (!f)
		return ;
	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		f(i, &s[i]);
		++i;
	}
}
