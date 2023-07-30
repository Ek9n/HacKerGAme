/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 20:09:36 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
void	setup_cluster_mlx(void)
{
	mlx_set_setting(MLX_DECORATED, 0);
}

void	setup_cluster(t_vars *vars)
{
	printf("HAPPY SAAD!\n");
	print_some_cool_cluster(vars);
	setup_cluster_sound(vars);
}

static void	print_some_cool_cluster_helper(t_vars *vars)
{
	mlx_image_to_window(vars->mlx, vars->key00, 28 * IMGSIZE, 14 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->tresor_door_closed, \
		21 * IMGSIZE, 7 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->tresor_door_up, \
		21 * IMGSIZE, 6 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->tresor_door_down, \
		21 * IMGSIZE, 8 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->saad, (vars->size_x / 2) * \
		IMGSIZE - 4 * IMGSIZE, vars->size_y * IMGSIZE - IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->server00, 24 * IMGSIZE, 0 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->kueche00, 24 * IMGSIZE, 10 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->kueche01, 24 * IMGSIZE, 14 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->black_kitchen, \
		22 * IMGSIZE, 10 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->black_server, \
		22 * IMGSIZE, 1 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->black_room, 1 * IMGSIZE, 1 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->room_point, 20 * IMGSIZE, 7 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->room_point, \
		20 * IMGSIZE, 12 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->room_point, \
		22 * IMGSIZE, 12 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->room_point, 22 * IMGSIZE, 7 * IMGSIZE);
	mlx_image_to_window(vars->mlx, vars->server_point, \
		25 * IMGSIZE + IMGSIZE / 2, 3 * IMGSIZE - IMGSIZE / 4);
}

void	print_some_cool_cluster(t_vars *vars)
{
	print_some_cool_cluster_helper(vars);
	set_image_depth(vars->tresor_door_closed, L_EXIT);
	set_image_depth(vars->tresor_door_up, L_EXIT);
	set_image_depth(vars->tresor_door_down, L_EXIT);
	set_image_depth(vars->saad, L_SOME);
	set_image_depth(vars->server00, L_SOME);
	set_image_depth(vars->kueche00, L_SOME);
	set_image_depth(vars->kueche01, L_SOME);
	set_image_depth(vars->key00, L_SOME);
	set_image_depth(vars->black_kitchen, L_DUST);
	set_image_depth(vars->black_server, L_DUST);
	set_image_depth(vars->black_room, L_DUST);
	set_image_depth(vars->room_point, L_POINT);
	set_image_depth(vars->server_point, L_POINT);
	vars->black_kitchen->enabled = true;
	vars->black_room->enabled = false;
	vars->room_point->enabled = false;
	vars->server_point->enabled = false;
	vars->server_flag = true;
}
