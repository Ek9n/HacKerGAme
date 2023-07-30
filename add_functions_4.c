/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/28 04:15:52 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
static void	death_animation_presetup(t_vars *vars)
{
	vars->player_l1->enabled = false;
	vars->player_l2->enabled = false;
	vars->player_r1->enabled = false;
	vars->player_r2->enabled = false;
	vars->player_u1->enabled = false;
	vars->player_u2->enabled = false;
	vars->player_d1->enabled = false;
	vars->player_d2->enabled = false;
	vars->blood0->instances[0].x = vars->player->instances[0].x;
	vars->blood0->instances[0].y = vars->player->instances[0].y;
	vars->blood1->instances[0].x = vars->player->instances[0].x;
	vars->blood1->instances[0].y = vars->player->instances[0].y;
	vars->blood2->instances[0].x = vars->player->instances[0].x;
	vars->blood2->instances[0].y = vars->player->instances[0].y;
	vars->deadguy0->instances[0].x = vars->player->instances[0].x;
	vars->deadguy0->instances[0].y = vars->player->instances[0].y;
	vars->deadguy0->enabled = true;
}

static void	death_animation_helper(t_vars *vars, const int img_num)
{
	vars->blood0->enabled = false;
	vars->blood1->enabled = false;
	vars->blood2->enabled = false;
	if (img_num == 0)
		vars->blood0->enabled = true;
	else if (img_num == 1)
		vars->blood1->enabled = true;
	else if (img_num == 2)
		vars->blood2->enabled = true;
}

void	death_animation(t_vars	*vars)
{
	static bool			flag;
	int					delay;
	static int			img_num;

	death_animation_presetup(vars);
	delay = 300;
	if (remote_delay_ms(delay))
		flag = true;
	if (flag == true && !remote_delay_ms(delay) && img_num < 3)
	{
		death_animation_helper(vars, img_num);
		img_num++;
		flag = false;
	}
	if (img_num > 2)
	{
		vars->blood0->enabled = true;
		vars->blood1->enabled = true;
		vars->blood2->enabled = true;
	}
}
