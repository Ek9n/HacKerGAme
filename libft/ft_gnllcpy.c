/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnllcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:49:46 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:35:10 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_gnllcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_gnllen(src));
	while (i < size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_gnllen(src));
}
