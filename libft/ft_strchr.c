/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:03:05 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:03:06 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*s == (char)c)
			return ((char*)(s));
		++s;
		++i;
	}
	return (NULL);
}
