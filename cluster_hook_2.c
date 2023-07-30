/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_hook_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 19:36:42 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
void	key_switch(t_vars *vars, mlx_image_t *img)
{
	if (check_hitbox_2(vars, img->instances[0], -20, -20) && \
		img->instances[0].enabled == true)
	{
		ma_sound_start(&vars->sound.take_key);
		mlx_image_to_window(vars->mlx, vars->key00, \
			14 * IMGSIZE + 3, 15 * IMGSIZE + IMGSIZE / 2 - 3);
		mlx_resize_image(vars->key00, 28, 28);
		mlx_set_instance_depth(&vars->key00->instances[1], L_POINT);
		vars->key_server = true;
		img->instances[0].enabled = false;
	}
}

void	light_switch(t_vars *vars)
{
	if (check_hitbox_2(vars, vars->room_point->instances[2], 0, 0))
	{
		vars->black_kitchen->enabled = false;
		vars->black_room->enabled = true;
	}
	else if (check_hitbox_2(vars, vars->room_point->instances[1], 0, 0))
	{
		vars->black_kitchen->enabled = true;
		vars->black_room->enabled = false;
	}
	else if (check_hitbox_2(vars, vars->room_point->instances[3], 0, 0))
	{
		vars->black_room->enabled = true;
		vars->black_server->enabled = false;
	}
	else if (check_hitbox_2(vars, vars->room_point->instances[0], 0, 0))
	{
		vars->black_room->enabled = false;
		vars->black_server->enabled = true;
	}
}

static void	room_switcher(t_vars *vars, int room_nbr)
{
	if (room_nbr == 0)
	{
		vars->entered_room[0] = true;
		vars->entered_room[1] = false;
		vars->entered_room[2] = false;
	}
	else if (room_nbr == 1)
	{
		vars->entered_room[0] = false;
		vars->entered_room[1] = true;
		vars->entered_room[2] = false;
	}
	else if (room_nbr == 2)
	{
		vars->entered_room[0] = false;
		vars->entered_room[1] = false;
		vars->entered_room[2] = true;
	}
}

void	enemy_switch(t_vars *vars)
{
	if (check_hitbox_2(vars, vars->room_point->instances[2], 0, 0))
		room_switcher(vars, 1);
	else if (check_hitbox_2(vars, vars->room_point->instances[1], 0, 0) || \
			check_hitbox_2(vars, vars->room_point->instances[0], 0, 0))
		room_switcher(vars, 0);
	else if (check_hitbox_2(vars, vars->room_point->instances[3], 0, 0))
		room_switcher(vars, 2);
}
