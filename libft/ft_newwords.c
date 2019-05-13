/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:02:50 by oltkache          #+#    #+#             */
/*   Updated: 2017/11/09 13:02:50 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_newwords(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = (char**)malloc(sizeof(char*) * (ft_numofwords(s, c) + 1));
	if (!res)
		return (0);
	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != c && s[i] != '\0')
		{
			++j;
			++i;
			if (s[i] == '\0' || s[i] == c)
				res[k++] = (char*)malloc(sizeof(char) * (j + 1));
		}
		++i;
	}
	return (res);
}
