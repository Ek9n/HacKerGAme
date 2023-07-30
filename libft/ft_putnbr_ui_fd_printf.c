/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ui_fd_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:31:49 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:31:49 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_ui_fd_printf(unsigned int nb, int fd, int *counter)
{
	if (nb >= 10)
	{
		ft_putnbr_fd_printf(nb / 10, fd, counter);
		ft_putnbr_fd_printf(nb % 10, fd, counter);
	}
	else
	{
		(*counter)++;
		ft_putchar_fd_printf(nb + '0', fd);
	}
	return (*counter);
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
