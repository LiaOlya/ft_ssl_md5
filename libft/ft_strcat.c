/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:02:21 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:02:23 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int j;
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	j = len2 + len1;
	s1[j] = '\0';
	while (j > len1)
	{
		s1[j - 1] = s2[j - len1 - 1];
		--j;
	}
	return (s1);
}
