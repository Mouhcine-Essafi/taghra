/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:14:25 by ajana             #+#    #+#             */
/*   Updated: 2022/06/30 20:07:08 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!*s)
		return (NULL);
	while (s[i])
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 2);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*save;
	ssize_t		n;

	n = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (n)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = 0;
		save = ft_strjoin_g(save, buff);
	}
	free (buff);
	line = get_line(save);
	return (line);
}
