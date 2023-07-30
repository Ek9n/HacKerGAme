/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pics_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:22:40 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/30 00:01:36 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	pics_init_zero(t_vars *vars)
{
	vars->tresor_door_closed = source_to_mlx_image_t(vars, \
		"./pictures/tresor_door_closed.png");
	vars->tresor_door_up = source_to_mlx_image_t(vars, \
		"./pictures/tresor_door_up.png");
	vars->tresor_door_down = source_to_mlx_image_t(vars, \
		"./pictures/tresor_door_down.png");
	if (vars->tresor_door_closed == NULL \
			|| vars->tresor_door_up == NULL || \
			vars->tresor_door_down == NULL)
		return (1);
	vars->wall = source_to_mlx_image_t(vars, "./pictures/wall00.png");
	vars->ground = source_to_mlx_image_t(vars, "./pictures/floor00.png");
	vars->tablet = source_to_mlx_image_t(vars, "./pictures/tabletbig.png");
	vars->black = source_to_mlx_image_t(vars, "./pictures/black.png");
	vars->black_kitchen = source_to_mlx_image_t(vars, \
		"./pictures/black_kitchen.png");
	vars->black_room = source_to_mlx_image_t(vars, \
		"./pictures/black_room.png");
	vars->black_server = source_to_mlx_image_t(vars, \
		"./pictures/black_server.png");
	vars->room_point = source_to_mlx_image_t(vars, \
		"./pictures/room_point.png");
	if (pics_init_one(vars) == 1)
		return (0);
	return (0);
}

int	pics_init_one(t_vars *vars)
{
	vars->server_point = source_to_mlx_image_t(vars, \
		"./pictures/room_point.png");
	vars->green_trans = source_to_mlx_image_t(vars, \
		"./pictures/green_trans.png");
	vars->red_trans = source_to_mlx_image_t(vars, "./pictures/red_trans.png");
	vars->purple_trans = source_to_mlx_image_t(vars, \
		"./pictures/purple_trans.png");
	vars->black_trans = source_to_mlx_image_t(vars, \
		"./pictures/black_trans.png");
	vars->alarmtext = source_to_mlx_image_t(vars, "./pictures/alarmtext.png");
	vars->kueche00 = source_to_mlx_image_t(vars, "./pictures/kueche00.png");
	vars->kueche01 = source_to_mlx_image_t(vars, "./pictures/kueche01.png");
	vars->server00 = source_to_mlx_image_t(vars, "./pictures/server00.png");
	vars->key00 = source_to_mlx_image_t(vars, "./pictures/key00.png");
	if (vars->wall == NULL || vars->ground == NULL || vars->tablet == NULL || \
			vars->black == NULL || \
			vars->black_kitchen == NULL || vars->black_room == NULL || \
			vars->room_point == NULL || vars->server_point == NULL || \
			vars->green_trans == NULL || vars->red_trans == NULL || \
			vars->kueche00 == NULL || vars->kueche01 == NULL || \
			vars->server00 == NULL || vars->key00 == NULL || \
			vars->purple_trans == NULL || vars->alarmtext == NULL || \
			vars->black_trans == NULL || vars->black_server == NULL)
		return (1);
	return (0);
}

int	pics_init_two(t_vars *vars)
{
	vars->coll = source_to_mlx_image_t(vars, "./pictures/tisch1.png");
	vars->coll2 = source_to_mlx_image_t(vars, "./pictures/tisch2.png");
	vars->gameexit = \
		source_to_mlx_image_t(vars, "./pictures/door_closed_l00.png");
	vars->openexit = \
		source_to_mlx_image_t(vars, "./pictures/door_open_l00.png");
	vars->enemy = source_to_mlx_image_t(vars, "./pictures/wheel00.png");
	vars->enemy2 = source_to_mlx_image_t(vars, "./pictures/wheel02.png");
	vars->enemy3 = source_to_mlx_image_t(vars, "./pictures/wheel01.png");
	vars->blood0 = source_to_mlx_image_t(vars, "./pictures/blood0.png");
	vars->blood1 = source_to_mlx_image_t(vars, "./pictures/blood1.png");
	vars->blood2 = source_to_mlx_image_t(vars, "./pictures/blood2.png");
	vars->deadguy0 = source_to_mlx_image_t(vars, "./pictures/deadguy0.png");
	vars->deadguy1 = source_to_mlx_image_t(vars, "./pictures/deadguy1.png");
	vars->deadguy2 = source_to_mlx_image_t(vars, "./pictures/deadguy2.png");
	if (vars->coll == NULL || vars->coll2 == NULL || vars->gameexit == NULL \
			|| vars->openexit == NULL || vars->enemy == NULL \
			|| vars->enemy2 == NULL || vars->enemy3 == NULL \
			|| vars->blood0 == NULL || vars->blood1 == NULL \
			|| vars->blood2 == NULL || vars->deadguy0 == NULL \
			|| vars->deadguy1 == NULL || vars->deadguy2 == NULL)
		return (1);
	return (0);
}

int	pics_init_three(t_vars *vars)
{
	vars->player = source_to_mlx_image_t(vars, "./pictures/guy_right2.png");
	vars->player_l1 = source_to_mlx_image_t(vars, "./pictures/guy_left1.png");
	vars->player_l2 = source_to_mlx_image_t(vars, "./pictures/guy_left2.png");
	vars->player_r1 = source_to_mlx_image_t(vars, "./pictures/guy_right1.png");
	vars->player_r2 = source_to_mlx_image_t(vars, "./pictures/guy_right2.png");
	vars->player_u1 = source_to_mlx_image_t(vars, "./pictures/guy_up1.png");
	vars->player_u2 = source_to_mlx_image_t(vars, "./pictures/guy_up2.png");
	vars->player_d1 = source_to_mlx_image_t(vars, "./pictures/guy_down1.png");
	vars->player_d2 = source_to_mlx_image_t(vars, "./pictures/guy_down2.png");
	vars->max_l = source_to_mlx_image_t(vars, "./pictures/max_l.png");
	vars->max_r = source_to_mlx_image_t(vars, "./pictures/max_r.png");
	vars->max_u = source_to_mlx_image_t(vars, "./pictures/max_u.png");
	vars->max_d = source_to_mlx_image_t(vars, "./pictures/max_d.png");
	if (vars->player == NULL || vars->player_l1 == NULL || \
			vars->player_l2 == NULL || vars->player_r1 == NULL || \
			vars->player_r2 == NULL || vars->player_u1 == NULL || \
			vars->player_u2 == NULL || vars->player_d1 == NULL || \
			vars->player_d2 == NULL || \
			vars->max_l == NULL || vars->max_r == NULL || \
			vars->max_u == NULL || vars->max_d == NULL)
		return (1);
	return (0);
}

int	pics_init_four(t_vars *vars)
{
	vars->saad = source_to_mlx_image_t(vars, "./pictures/saady.png");
	if (vars->saad == NULL)
		return (1);
	return (0);
}
