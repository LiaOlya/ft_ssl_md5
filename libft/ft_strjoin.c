/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:22:58 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:22:59 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	k = ft_strlen(s1);
	len = ft_strlen(s2) + k;
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (i < len)
	{
		if (i >= k)
			res[i] = s2[j++];
		else
			res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
