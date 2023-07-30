/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:33:55 by hstein            #+#    #+#             */
/*   Updated: 2022/12/20 01:33:55 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_checknegative(int *ptr_n, size_t *sign)
{
	*sign = 0;
	if (*ptr_n < 0)
	{
		*ptr_n *= -1;
		*sign = 1;
	}
}

static char	*ft_strprep(int n, size_t *cnt, size_t *sign)
{
	char	*strtoprep;

	ft_checknegative(&n, sign);
	*cnt = 1;
	while (n > 9)
	{
		n /= 10;
		(*cnt)++;
	}
	strtoprep = malloc(*cnt + 1 + *sign);
	if (!strtoprep)
		return (NULL);
	if (*sign == 1)
		strtoprep[0] = '-';
	strtoprep[*cnt + *sign] = '\0';
	return (strtoprep);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	digits;
	size_t	sign;

	if (n == -2147483648)
	{
		str = malloc(12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	str = ft_strprep(n, &digits, &sign);
	if (!str)
		return (NULL);
	if (sign == 1)
		n *= -1;
	while (digits--)
	{
		str[digits + sign] = n % 10 + 48;
		if (digits > 0)
			n = n / 10;
	}
	return (str);
}
