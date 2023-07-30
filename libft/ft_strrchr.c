/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:14:15 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:30:16 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*a;
	char	b;

	i = 0;
	a = (char *) s;
	b = (char) c;
	while (i <= ft_strlen(a))
	{
		if (a[ft_strlen(a) - i] == b)
			return (&a[ft_strlen(a) - i]);
		i++;
	}
	return (0);
}

/*int main()
{
	char	test[] = "abcdeabcde";
	char	c = 'c';

	printf("%s\n", ft_strrchr(test, c));
}*/
