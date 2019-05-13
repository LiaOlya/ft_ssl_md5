/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:02:49 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:02:50 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dst_copy;
	char	*src_copy;
	size_t	l;
	size_t	i;

	i = size;
	dst_copy = dst;
	src_copy = (char*)src;
	while (i-- != 0 && *dst_copy != '\0')
		++dst_copy;
	l = dst_copy - dst;
	i = size - l;
	if (i == 0)
		return (l + ft_strlen(src_copy));
	while (*src_copy != '\0')
	{
		if (i != 1)
		{
			*dst_copy++ = *src_copy;
			--i;
		}
		src_copy++;
	}
	*dst_copy = '\0';
	return (l + (src_copy - src));
}
