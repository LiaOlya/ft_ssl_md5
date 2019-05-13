/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:03:44 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:03:45 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (ft_isascii(s1[i]) && ft_isascii(s2[i]))
				return (s1[i] - s2[i]);
			else
				return (s2[i] - s1[i]);
		}
		++i;
	}
	return (0);
}
