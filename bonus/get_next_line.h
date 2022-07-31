/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:33:41 by ajana             #+#    #+#             */
/*   Updated: 2022/06/30 20:52:19 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_g(char *s1, char *s2);
size_t	ft_strlen(const char *str);

#endif