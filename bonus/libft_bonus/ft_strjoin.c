/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:35:41 by messafi           #+#    #+#             */
/*   Updated: 2021/12/14 00:44:56 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	z;
	char	*blank;
	int		len;

	i = 0;
	z = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	blank = (char *)malloc(sizeof(char) * (len + 1));
	if (!blank)
		return (0);
	while (s1[i] != '\0')
	{
		blank[i] = s1[i];
		i++;
	}
	while (s2[z] != '\0')
	{
		blank[i++] = s2[z++];
	}
	blank[i] = '\0';
	return (blank);
}
