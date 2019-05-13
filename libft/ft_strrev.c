/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:14:33 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/09 14:14:35 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;
	size_t	n;
	char	*res;

	len = ft_strlen(s);
	i = 0;
	n = len - 1;
	res = (char*)malloc(sizeof(char) * len);
	while (i < len)
	{
		res[i] = s[n];
		++i;
		--n;
	}
	res[i] = '\0';
	return (res);
}
