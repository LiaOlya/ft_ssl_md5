/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:26:58 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:26:59 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;

	d = (unsigned char*)dst;
	if (dst > src)
		while (len--)
			*((unsigned char*)(dst + len)) = *(unsigned char*)(src + len);
	else if (dst < src)
		while (len--)
		{
			*(unsigned char*)dst = *(unsigned char*)src;
			++dst;
			++src;
		}
	return (d);
}
