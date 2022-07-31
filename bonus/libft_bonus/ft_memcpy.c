/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:11:22 by messafi           #+#    #+#             */
/*   Updated: 2021/11/27 15:48:00 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*altdst;
	unsigned char	*altsrc;

	altdst = (unsigned char *)dst;
	altsrc = (unsigned char *)src;
	if (altsrc == 0 && altdst == 0)
		return (0);
	while (n > 0)
	{
		*altdst = *altsrc;
		altdst++;
		altsrc++;
		n--;
	}
	return (dst);
}
