/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:24:01 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:24:02 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		j;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	if (i == len)
		return (ft_strdup(""));
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		--len;
	len -= i;
	res = (char*)malloc(sizeof(char) * (len + 2));
	if (res == NULL)
		return (NULL);
	j = 0;
	while (j < len)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
