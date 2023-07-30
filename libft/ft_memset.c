/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:52:00 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:33:07 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_memset(char *target, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		target[i] = (unsigned char) value;
		i++;
	}
	return (target);
}
