/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_max_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:25:15 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 18:33:31 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	max_init(t_vars *vars, int x, int y)
{
	if (vars->max_l->count == 0)
	{
		mlx_image_to_window(vars->mlx, vars->max_r, x - IMGSIZE, y - IMGSIZE);
		mlx_image_to_window(vars->mlx, vars->max_l, x - IMGSIZE, y + IMGSIZE);
		mlx_image_to_window(vars->mlx, vars->max_u, x - (2 * IMGSIZE), y);
		mlx_image_to_window(vars->mlx, vars->max_d, x, y);
	}
}

void	max_set_trash(t_vars *vars)
{
	set_image_depth(vars->max_l, L_TRASH);
	set_image_depth(vars->max_r, L_TRASH);
	set_image_depth(vars->max_u, L_TRASH);
	set_image_depth(vars->max_d, L_TRASH);
}
