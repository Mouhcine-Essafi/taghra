/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:08:04 by messafi           #+#    #+#             */
/*   Updated: 2021/11/21 22:10:13 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem_loc;

	mem_loc = malloc(count * size);
	if (mem_loc == NULL)
		return (NULL);
	ft_bzero(mem_loc, count * size);
	return (mem_loc);
}
