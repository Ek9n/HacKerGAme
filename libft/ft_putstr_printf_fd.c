/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:31:38 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:31:38 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_printf_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
	return (i);
}

/*int main()
{
    ft_putstr_fd("hello world", 1);
}*/
