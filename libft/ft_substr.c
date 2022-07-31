/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:33:52 by messafi           #+#    #+#             */
/*   Updated: 2021/11/26 14:16:49 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*blank;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		blank = malloc(1);
		*blank = '\0';
		return (blank);
	}
	if (ft_strlen(s) - start <= len)
		return (ft_strdup(&s[start]));
	blank = malloc(len + 1);
	if (!blank)
		return (0);
	while (s[start + i] != '\0' && i < len)
	{
		blank[i] = s[start + i];
		i++;
	}
	blank[i] = '\0';
	return (blank);
}
