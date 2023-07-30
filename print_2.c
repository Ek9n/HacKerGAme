/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:06:30 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/26 08:05:49 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	print_map(t_vars *vars)
{
	int	xs;
	int	ys;

	ys = -1;
	if (!print_ground(vars))
		return (0);
	while (++ys < vars->size_y)
	{
		xs = -1;
		while (++xs < vars->size_x)
			if (!print_img(vars, xs, ys))
				return (0);
	}
	return (1);
}

void	set_image_depth(mlx_image_t *image, int z)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		mlx_set_instance_depth(&image->instances[i], z);
		i++;
	}
}

static void	set_depth_helper(t_vars *vars)
{
	set_image_depth(vars->player_r2, L_PLAYER);
	set_image_depth(vars->player_l2, L_PLAYER);
	set_image_depth(vars->player_u2, L_PLAYER);
	set_image_depth(vars->player_d2, L_PLAYER);
	set_image_depth(vars->gameexit, L_EXIT);
	set_image_depth(vars->openexit, L_EXIT);
	vars->openexit->instances[0].enabled = false;
}

void	set_depth(t_vars *vars)
{
	set_image_depth(vars->enemy, L_ENEMY);
	set_image_depth(vars->black, L_DUST);
	set_image_depth(vars->ground, L_GROUND);
	set_image_depth(vars->wall, L_WALL);
	set_image_depth(vars->coll, L_COLLECTIBLE);
	set_image_depth(vars->player, L_PLAYER);
	set_image_depth(vars->player_r1, L_PLAYER);
	set_image_depth(vars->player_l1, L_PLAYER);
	set_image_depth(vars->player_u1, L_PLAYER);
	set_image_depth(vars->player_d1, L_PLAYER);
	set_image_depth(vars->player_r2, L_PLAYER);
	set_depth_helper(vars);
}

void	spawn_player_imgs(t_vars *vars)
{
	vars->player_l1->enabled = false;
	vars->player_l2->enabled = false;
	vars->player_r1->enabled = false;
	vars->player_r2->enabled = false;
	vars->player_u1->enabled = false;
	vars->player_u2->enabled = false;
	vars->player_d1->enabled = false;
	vars->player_d2->enabled = false;
	mlx_set_instance_depth(&vars->player_l1->instances[0], L_PLAYER);
	mlx_set_instance_depth(&vars->player_l2->instances[0], L_PLAYER);
	mlx_set_instance_depth(&vars->player_r1->instances[0], L_PLAYER);
	mlx_set_instance_depth(&vars->player_r2->instances[0], L_PLAYER);
	mlx_set_instance_depth(&vars->player_u1->instances[0], L_PLAYER);
	mlx_set_instance_depth(&vars->player_u2->instances[0], L_PLAYER);
	mlx_set_instance_depth(&vars->player_d1->instances[0], L_PLAYER);
	mlx_set_instance_depth(&vars->player_d2->instances[0], L_PLAYER);
}
