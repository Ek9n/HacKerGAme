/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:28:15 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/29 19:59:20 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	return_free_split(char **map, char *s)
{
	ft_free(map);
	ft_error_sl(s);
	return (1);
}

int	line_check(t_vars *vars, int i)
{
	int		j;
	size_t	k;

	j = -1;
	while (++j < i)
	{
		k = -1;
		if (j == 0 || j == i - 1)
			while (++k < ft_strlen(vars->map[j]))
				if (vars->map[j][k] != '1')
					return (0);
		k = -1;
		while (++k < ft_strlen(vars->map[j]))
			if (k == 0 || k == (ft_strlen(vars->map[j]) - 1))
				if (vars->map[j][k] != '1')
					return (0);
	}
	return (1);
}

int	same_length(t_vars *vars, int i)
{
	int		j;
	size_t	len;

	j = 0;
	len = ft_strlen(vars->map[j]);
	while (++j < i)
		if (ft_strlen(vars->map[j]) != len)
			return (0);
	return (1);
}

char	**dup_string_arr(char **original, int length)
{
	int		i;
	char	**new;
	int		len;

	i = 0;
	new = malloc((length + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (i < length)
	{
		len = ft_strlen(original[i]) + 1;
		new[i] = malloc(len * sizeof(char));
		if (new[i] == NULL)
		{
			ft_free(new);
			return (NULL);
		}
		ft_strlcpy(new[i], original[i], len);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	which_instance(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->coll->count)
	{
		if (vars->coll->instances[i].x == vars->player->instances[0].x && \
			vars->coll->instances[i].y == vars->player->instances[0].y)
			return (i);
		i++;
	}
	return (-1);
}
