/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:31:59 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:31:59 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_printf(int nb, int fd, int *ctr)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (nb < 0)
		{
			(*ctr)++;
			write(fd, "-", 1);
			nb *= -1;
		}
		if (nb >= 10)
		{
			ft_putnbr_fd_printf(nb / 10, fd, ctr);
			ft_putnbr_fd_printf(nb % 10, fd, ctr);
		}
		else
		{
			(*ctr)++;
			ft_putchar_fd_printf(nb + '0', fd);
		}
	}
	return (*ctr);
}
/*
int main()
{
	int counter = 0;
    int len = 0;
	len = ft_putnbr_fd_printf(12345678, 1, &counter);
	printf("%d\n", len);
}
*/
