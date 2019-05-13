/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:26:41 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:26:42 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (*s2 == (unsigned char)c)
		{
			s1[i] = *s2;
			return (s1 + i + 1);
		}
		s1[i] = *s2;
		++i;
		++s2;
	}
	return (NULL);
}
