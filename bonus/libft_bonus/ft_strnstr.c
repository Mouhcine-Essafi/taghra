/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:21:08 by messafi           #+#    #+#             */
/*   Updated: 2021/11/22 00:01:36 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;
	char	*str;
	char	*to_find;

	x = 0;
	y = 0;
	str = (char *)haystack;
	to_find = (char *)needle;
	while (x < ft_strlen(str) && y < ft_strlen(to_find) && x < len)
	{
		if (str[x] == to_find[y])
		{
			x++;
			y++;
		}
		else
		{
			x = x - y + 1;
			y = 0;
		}
	}
	if (y == ft_strlen(to_find))
		return (&str[x - y]);
	return (0);
}
