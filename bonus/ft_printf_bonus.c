/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 02:46:31 by messafi           #+#    #+#             */
/*   Updated: 2022/07/25 20:16:44 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_putchar(char c, int i)
{
	write (1, &c, 1);
		i++;
	return (i);
}

int	ft_printstr(char *str, int i)
{
	if (str == NULL)
	{
		write (1, "(null)", 6);
		i += 6;
		return (i);
	}
	while (*str != '\0' )
	{
		i = ft_putchar(*str++, i);
	}
	return (i);
}

int	ft_putnbrsigned(int n, int i)
{
	if (n > -2147483648 && n < 0)
	{
		i = ft_putchar('-', i);
		i = ft_putnbrsigned(n * (-1), i);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		i += 11;
	}
	else if (n > 9)
	{
		i = ft_putnbrsigned(n / 10, i);
		i = ft_putnbrsigned(n % 10, i);
	}
	else
	{
		i = ft_putchar(n + '0', i);
	}
	return (i);
}

static int	print(char form, va_list pp, int i)
{
	if (form == 's')
		i = ft_printstr(va_arg(pp, char *), i);
	if (form == 'd' || form == 'i')
		i = ft_putnbrsigned(va_arg(pp, int), i);
	if (form == '%')
		i = ft_putchar('%', i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	char	form;
	va_list	pp;

	i = 0;
	va_start(pp, format);
	while (*format != '\0')
	{
		form = *format;
		if (form == '%')
		{
			format++;
			form = *format;
			i = print(form, pp, i);
		}
		else
			i = ft_putchar(form, i);
		format++;
	}
	va_end(pp);
	return (i);
}
