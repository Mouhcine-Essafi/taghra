/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:11:11 by messafi           #+#    #+#             */
/*   Updated: 2021/11/27 16:13:33 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	index(const char *s)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (s[i] == '+')
	{
		i++;
		if (s[i] == '-')
			return (0);
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	res = 0;
	sign = 1;
	i = index(str);
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] < 48 && str[i] > 57)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		if (res > 9223372036854775807 && sign == -1)
			return (0);
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		i++;
	}
	return (res * sign);
}
