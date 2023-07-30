/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:25:52 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/28 03:26:48 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	valid_chars(t_vars *vars, int i)
{
	int		j;
	size_t	k;
	char	**tmp;

	j = -1;
	tmp = vars->map;
	while (++j < i)
	{
		k = -1;
		while (++k < ft_strlen(tmp[j]))
			if (!setting_ctrs(vars, j, k, tmp[j][k]))
				return (0);
	}
	if (vars->p_ctr != 1 || vars->e_ctr != 1 || vars->c_ctr < 1)
		return (0);
	else
		return (1);
}

int	invalid_path(t_vars *vars, int i)
{
	char	**tmp;
	t_vars	dup;

	tmp = dup_string_arr(vars->map, i);
	dup.p_ctr = vars->p_ctr;
	dup.c_ctr = vars->c_ctr;
	dup.e_ctr = vars->e_ctr;
	dup.size_x = vars->size_x;
	dup.size_y = vars->size_y;
	flood_fill(tmp, &dup, vars->start);
	ft_free(tmp);
	if (dup.c_ctr > 0 || dup.e_ctr > 0)
		return (1);
	return (0);
}

int	error_check(t_vars *vars, int i)
{
	if (!same_length(vars, i))
		return (return_free_split(vars->map, "Error\nLine length wrong\n"));
	if (!line_check(vars, i))
		return (return_free_split(vars->map, "Error\nLines not valid\n"));
	if (!valid_chars(vars, i))
		return (return_free_split(vars->map, "Error\nNot valid chars\n"));
	if (invalid_path(vars, i))
		return (return_free_split(vars->map, "Error\nNo valid path\n"));
	return (0);
}
