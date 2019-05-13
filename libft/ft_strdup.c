/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:05:08 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:05:08 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	res = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
