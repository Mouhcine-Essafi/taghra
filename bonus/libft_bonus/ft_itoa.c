/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:04:56 by messafi           #+#    #+#             */
/*   Updated: 2021/11/23 01:31:42 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*strnew(int size, int n)
{
	char	*temp;
	int		i;

	i = 0;
	if (n == 0 || n > 0)
		temp = malloc(sizeof(*temp) * (size + 1));
	else
		temp = malloc(sizeof(*temp) * (size + 2));
	if (!temp)
		return (NULL);
	if (temp)
	{
		while (i < size + 1)
		{
			temp[i] = '\0';
			i++;
		}
	}
	return (temp);
}

static	void	isnegative(char *s, int n, size_t len)
{
	char	*z;
	char	a;

	if (n < 0)
	{
		s[len--] = '-';
		s[len + 2] = '\0';
	}
	if (n > 0)
		s[len++] = '\0';
	z = s + ft_strlen(s) - 1;
	while (s < z)
	{
		a = *s;
		*s++ = *z;
		*z-- = a;
	}
}

static	size_t	count_numbers(int n)
{
	size_t	i;

	i = 0;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

static	char	*iszero(char *c, int n)
{
	if (n == 0)
		*c = '0';
	return (c);
}

char	*ft_itoa(int n)
{
	char		*s;
	size_t		i;
	size_t		len;
	int			alts;

	len = count_numbers(n);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = strnew(len, n);
	if (!s)
		return (NULL);
	if (n < 0)
		alts = n * -1;
	if (n > 0)
		alts = n;
	iszero(s, n);
	while (i <= len && n != 0)
	{
		s[i++] = alts % 10 + '0';
		alts /= 10;
	}
	isnegative(s, n, len);
	return (s);
}
