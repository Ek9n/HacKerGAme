/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:31:07 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:31:07 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*static void	ft_toupper2(unsigned int i, char * chr)
{
	while (chr[i] != '\0')
	{
		if (97 <= chr[i] && chr[i] <= 122)
			chr[i] = chr[i] - 32;
		i++;
	}
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/*
int main()
{
	char	test[] = "abcde";

	ft_striteri(test, &ft_toupper2);
	printf("%s\n", test);
}*/
