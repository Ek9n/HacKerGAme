/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:17:36 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:33:01 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

static int	diu(const char *str, va_list args, int i)
{
	int	len;
	int	counter;

	len = 0;
	counter = 0;
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		len += ft_putnbr_fd_printf(va_arg(args, int), 1, &counter);
	else if (str[i + 1] == 'u')
		len += ft_putnbr_ui_fd_printf(va_arg(args, unsigned int), 1, &counter);
	return (len);
}

static int	xxp(const char *str, va_list args, int i)
{
	int	len;
	int	c;

	len = 0;
	c = 0;
	if (str[i + 1] == 'x')
		len += ft_putnbr_base_fd(va_arg(args, unsigned int), "abcdef", 1, &c);
	else if (str[i + 1] == 'X')
		len += ft_putnbr_base_fd(va_arg(args, unsigned int), "ABCDEF", 1, &c);
	else if (str[i + 1] == 'p')
		len += ft_voidcase(va_arg(args, long long), "abcdef", 1, &c);
	return (len);
}

static int	elseout(const char *str, va_list args, int i)
{
	int	len;

	len = 0;
	if (str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u')
		len += diu(str, args, i);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == 'p')
		len += xxp(str, args, i);
	else if (str[i + 1] == 'c')
		len += ft_putchar_fd_printf(va_arg(args, unsigned int), 1);
	else if (str[i + 1] == 's')
		len += ft_putstr_printf_fd(va_arg(args, char *), 1);
	else if (str[i + 1] == '%')
		len += ft_putchar_fd_printf('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%' && str[i] != '\0')
		{
			len += ft_putchar_fd_printf(str[i], 1);
		}
		else
		{
			len += elseout(str, args, i);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
