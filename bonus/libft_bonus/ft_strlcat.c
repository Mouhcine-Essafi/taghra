/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:24:01 by messafi           #+#    #+#             */
/*   Updated: 2021/11/21 22:24:41 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		altdst;
	size_t		altsrc;
	size_t		i;

	if (!dstsize)
		return (ft_strlen(src));
	altsrc = ft_strlen(src);
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	altdst = i;
	while (src[i - altdst] && i < dstsize - 1)
	{
		dst[i] = src[i - altdst];
		i++;
	}
	if (altdst < dstsize)
		dst[i] = '\0';
	return (altdst + altsrc);
}
