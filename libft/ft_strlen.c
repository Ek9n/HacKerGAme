/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:51:18 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:30:39 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*int main(int a, char **b)
{
	if (a != 2)
		return (-1);
	else
	{
		printf("%lu\n", strlen(b[1]));
	}
	return (0);
}*/
