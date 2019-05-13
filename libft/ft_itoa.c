/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:24:19 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:24:20 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_i(int n)
{
	long long i;

	i = 1;
	while (i * 10 <= n)
		i *= 10;
	return (i);
}

static int			ft_num(int n)
{
	long long	i;
	int			res;

	i = 1;
	res = 1;
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		res = 2;
		n *= -1;
	}
	while (i * 10 <= n)
	{
		i *= 10;
		++res;
	}
	return (res + 1);
}

static char			*ft_help(int n, long long i, long long j, char *res)
{
	while (i > 1)
	{
		if (n % i != 0)
		{
			i /= 10;
			res[j] = (n %= (i * 10)) / i + '0';
		}
		else
			res[j] = n % (i /= 10) + '0';
		++j;
	}
	res[j] = '\0';
	return (res);
}

char				*ft_itoa(int n)
{
	char		*res;
	long long	i[2];

	i[1] = 0;
	res = (char*)malloc(sizeof(char) * ft_num(n));
	if (!res)
		return (0);
	if (n < 0)
	{
		res[i[1]++] = '-';
		if (n == -2147483648)
		{
			res[i[1]++] = '2';
			n = -147483648;
		}
		n *= -1;
	}
	i[0] = ft_i(n);
	res[i[1]++] = n / i[0] + '0';
	res = ft_help(n, i[0], i[1], res);
	return (res);
}
