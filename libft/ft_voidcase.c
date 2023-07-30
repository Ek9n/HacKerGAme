/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidcase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:29:24 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:29:25 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_voidcase(long long int vptr, char *s, int fd, int *counter)
{
	if (!vptr)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		*counter = (*counter) + 2;
		ft_putnbr_base_fd(vptr, s, fd, counter);
	}
	return (*counter);
}
