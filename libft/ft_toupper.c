/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:02:49 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:29:31 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int chr)
{
	if (97 <= chr && chr <= 122)
		return (chr - 32);
	else
		return (chr);
}

/*int	main(int a, char **b)
{
	(void) a;
	printf("%c\n", toupper(*b[1]));
}*/
