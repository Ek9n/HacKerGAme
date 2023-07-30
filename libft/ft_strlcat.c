/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:30:55 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:30:55 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	i = 0;
	if (len > size)
		return (ft_strlen(src) + size);
	else
	{
		while (len + i + 1 < size && src[i] != '\0')
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
		return (len + ft_strlen(src));
	}
}
/*
int main()
{
    char    target1[] = "abcde";
	char	target2[] = "abcde";
    char    source[] = "fghij";
    size_t  n = 3;

    printf("ft_: %lu\n", ft_strlcat(target1, source, n));
	printf("org: %lu\n", strlcat(target2, source, n));
    printf("t1: %s\n", target1);
	printf("t2: %s\n", target2);
}*/
