/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:22:35 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:35:21 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*s;

	s = (void *) malloc(num * size);
	if (s == NULL)
		return (0);
	else
	{
		ft_bzero(s, num * size);
		return (s);
	}
}
