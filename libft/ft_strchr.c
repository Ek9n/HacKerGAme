/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:08:06 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:31:28 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*b;

	i = 0;
	a = (char) c;
	b = (char *) s;
	while (b[i])
	{
		if (b[i] == a)
			return (&b[i]);
		i++;
	}
	if (b[i] == a)
		return (&b[i]);
	return (0);
}
/*
int main()
{
	char	check[] = "abcdefg";
	char	c = 'c' + 256;

	printf("%s\n", ft_strchr(check, c));
printf("%c\n", c);
}*/
