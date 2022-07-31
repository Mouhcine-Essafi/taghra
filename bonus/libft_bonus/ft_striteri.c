/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:44:29 by messafi           #+#    #+#             */
/*   Updated: 2021/11/26 11:15:17 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	len = ft_strlen(s);
	if (s != 0)
	{
		while (i < len)
		{
			f(i, &s[i]);
			i++;
		}
		s[i] = '\0';
	}
}
