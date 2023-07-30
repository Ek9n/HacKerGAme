/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:30:24 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:30:27 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0' && ((i + j) < len))
			j++;
		if (little[j] == '\0')
			return (&((char *)big)[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char	str[] = "abcbcdefg";
	char	to_find[] = "bcd";
	size_t	i = 5;

	printf("%s\n", ft_strnstr(str, to_find, i));
	printf("%s\n", strnstr(str, to_find, i));
}*/
