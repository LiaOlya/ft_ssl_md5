/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:25:05 by oltkache          #+#    #+#             */
/*   Updated: 2017/10/30 20:25:05 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned long long	i;

	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		n *= -1;
	}
	i = 1;
	while ((i * 10) <= n)
		i *= 10;
	ft_putchar(n / i + '0');
	while (i > 1)
	{
		i /= 10;
		if (n % (i * 10) != 0)
			ft_putchar((n %= (i * 10)) / i + '0');
		else
			ft_putchar(n % i + '0');
	}
}
