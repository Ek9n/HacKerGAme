/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:45:50 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:32:16 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(unsigned long long nb, char *base, int fd, int *counter)
{
	if (nb >= 16)
	{
		ft_putnbr_base_fd(nb / 16, base, fd, counter);
		ft_putnbr_base_fd(nb % 16, base, fd, counter);
	}
	else
	{
		if (nb < 10)
		{
			(*counter)++;
			ft_putchar_fd_printf(nb + '0', fd);
		}
		else
		{
			(*counter)++;
			ft_putchar_fd_printf(base[nb - 10], fd);
		}
	}
	return (*counter);
}
/*
int main()
{
    ft_putnbr_base_fd(33, "ABCDEF", 1);
    return (0);
}
*/
