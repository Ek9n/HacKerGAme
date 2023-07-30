/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:58:44 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:29:36 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	else
		return (c);
}

/*int main()
{
	printf("A: %c\n", ft_tolower('A'));
	printf("a: %c\n", ft_tolower('a'));
	char text[] = "Welcome2C programming !!!\n";
	int i = 0;
	while( text[i] )
	{
    	printf( "%c", ft_tolower(text[i])); 
    	i++;
	}
}*/
