/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_max_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:25:15 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 18:37:16 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	max_attack2(t_vars *vars)
{
	if ((search_through_instances2(vars, vars->max_l) > -1) || \
		(search_through_instances2(vars, vars->max_r) > -1) || \
		(search_through_instances2(vars, vars->max_u) > -1) || \
		(search_through_instances2(vars, vars->max_d) > -1))
		return (1);
	return (0);
}

void	little_rip_helper(t_vars *vars, int win_lose_flag, \
			int stop_flag, int d_sound)
{
	vars->win_lose_flag = win_lose_flag;
	vars->stop_flag = stop_flag;
	kill_sound(vars, d_sound);
	death_animation(vars);
}

void	max_patrol_helper(t_vars *vars, int x, int y, int delay)
{
	if (delay && vars->enemys.max.run_flag == false && vars->stop_flag == 0)
	{
		x *= IMGSIZE;
		y *= IMGSIZE;
		max_init(vars, x, y);
		max_set_trash(vars);
		if (vars->enemys.max.n == 0)
			set_image_depth(vars->max_d, L_ENEMY);
		else if (vars->enemys.max.n == 1)
			set_image_depth(vars->max_l, L_ENEMY);
		else if (vars->enemys.max.n == 2)
			set_image_depth(vars->max_u, L_ENEMY);
		else if (vars->enemys.max.n == 3)
			set_image_depth(vars->max_r, L_ENEMY);
		vars->enemys.max.n++;
		if (vars->enemys.max.n == 4)
			vars->enemys.max.n = 0;
		vars->enemys.max.run_flag = true;
	}
	else if (!delay)
		vars->enemys.max.run_flag = false;
}

void	max_patrol(t_vars *vars, int x, int y)
{
	int	delay;

	if (vars->entered_room[1] == true)
	{
		delay = remote_delay_ms(200);
		ma_sound_set_looping(&vars->sound.dog_barking2, 1);
		ma_sound_start(&vars->sound.dog_barking2);
		max_patrol_helper(vars, x, y, delay);
		if (max_attack2(vars))
		{
			ma_sound_stop(&vars->sound.dog_barking2);
			printf("WUFF!!!\n");
			vars->stop_flag = true;
			little_rip_helper(vars, 1, 1, 1);
		}
	}
	else
	{
		ma_sound_stop(&vars->sound.dog_barking2);
	}
}
