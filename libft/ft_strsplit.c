/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:23:47 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:23:47 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	if (s == NULL || !(res = ft_newwords(s, c)))
		return (NULL);
	k = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		j = 0;
		while (s[i] != c && s[i] != '\0')
		{
			res[k][j] = s[i];
			++j;
			++i;
			if (s[i] == '\0' || s[i] == c)
				res[k++][j] = '\0';
		}
		if (s[i] == '\0')
			break ;
	}
	res[k] = 0;
	return (res);
}
