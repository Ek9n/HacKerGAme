/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_hook_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 19:36:10 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions

void	cluster_hook(t_vars *vars)
{
	hack_server(vars);
	open_tresor_door(vars);
	light_switch(vars);
	enemy_switch(vars);
	key_switch(vars, vars->key00);
	max_patrol(vars, 27, 12);
	if (vars->entered_room[2] && vars->server_flag == true)
	{
		ma_sound_stop(&vars->sound.track1);
		ma_sound_set_looping(&vars->sound.server, 1);
		ma_sound_start(&vars->sound.server);
	}
	else if (vars->entered_room[0] && vars->server_flag == false)
	{
		ma_sound_stop(&vars->sound.heartbeat);
		ma_sound_set_looping(&vars->sound.track2, 1);
		ma_sound_start(&vars->sound.track2);
		light_scene2(vars, 100);
	}
}

void	kill_sound(t_vars *vars, int track_nbr)
{
	if (track_nbr == 0)
		ma_sound_start(&vars->sound.rip);
	else if (track_nbr == 1)
		ma_sound_start(&vars->sound.eating);
}

void	open_tresor_door_helper(t_vars *vars)
{
	ma_sound_start(&vars->sound.tresor_door_open);
	vars->tresor_door_up->instances[0].enabled = true;
	vars->tresor_door_down->instances[0].enabled = true;
	vars->tresor_door_closed->instances[0].enabled = false;
}

void	open_tresor_door(t_vars *vars)
{
	static bool	flag;

	if (check_hitbox_2(vars, vars->tresor_door_closed->instances[0], 0, 0) \
		&& vars->tresor_door_closed->instances[0].enabled == \
		true && vars->key_server == true)
	{
		open_tresor_door_helper(vars);
		flag = true;
	}
	else if (vars->player->instances[0].x < \
		vars->tresor_door_closed->instances[0].x - IMGSIZE || \
		vars->player->instances[0].x > \
		vars->tresor_door_closed->instances[0].x + IMGSIZE)
	{
		if (flag)
		{
			ma_sound_start(&vars->sound.tresor_door_open);
			flag = false;
		}
		vars->tresor_door_up->instances[0].enabled = false;
		vars->tresor_door_down->instances[0].enabled = false;
		vars->tresor_door_closed->instances[0].enabled = true;
	}
}
