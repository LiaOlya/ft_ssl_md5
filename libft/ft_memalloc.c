/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:26:13 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:26:14 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void *)malloc(sizeof(void) * size);
	if (mem == 0)
		return (0);
	ft_memset(mem, 0, size);
	return (mem);
}
