/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:23:26 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:23:26 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	int				len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
