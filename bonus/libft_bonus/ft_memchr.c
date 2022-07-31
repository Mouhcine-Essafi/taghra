/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:18:37 by messafi           #+#    #+#             */
/*   Updated: 2021/11/26 14:00:37 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (mem[i] == (unsigned char)c)
			return (&mem[i]);
		i++;
	}
	return (NULL);
}
