/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:30:40 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 21:46:25 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	img_enabler(mlx_image_t *a, mlx_image_t *b)
{
	if (a->enabled == true)
	{
		a->enabled = false;
		b->enabled = true;
	}
	else if (a->enabled == false)
	{
		a->enabled = true;
		b->enabled = false;
	}
}

void	run_process(t_vars *vars, mlx_image_t *a, mlx_image_t *b)
{
	int			delay_state;
	static bool	flag;

	a->instances[0].x = vars->player->instances[0].x;
	a->instances[0].y = vars->player->instances[0].y;
	b->instances[0].x = vars->player->instances[0].x;
	b->instances[0].y = vars->player->instances[0].y;
	delay_state = remote_delay_ms(140);
	if (a->enabled == false && b->enabled == false)
		a->enabled = true;
	if (delay_state && flag == false)
	{
		img_enabler(a, b);
		flag = true;
	}
	else if (!delay_state)
		flag = false;
}

static void	run_img_falser_helper(t_vars *vars, int direction)
{
	if (direction == 3)
	{
		vars->player_l1->enabled = false;
		vars->player_r1->enabled = false;
		vars->player_d1->enabled = false;
		vars->player_l2->enabled = false;
		vars->player_r2->enabled = false;
		vars->player_d2->enabled = false;
	}
	else if (direction == 4)
	{
		vars->player_l1->enabled = false;
		vars->player_r1->enabled = false;
		vars->player_u1->enabled = false;
		vars->player_l2->enabled = false;
		vars->player_r2->enabled = false;
		vars->player_u2->enabled = false;
	}
}

void	run_img_falser(t_vars *vars, int direction)
{
	if (direction == 1)
	{
		vars->player_r1->enabled = false;
		vars->player_u1->enabled = false;
		vars->player_d1->enabled = false;
		vars->player_r2->enabled = false;
		vars->player_u2->enabled = false;
		vars->player_d2->enabled = false;
	}
	else if (direction == 2)
	{
		vars->player_l1->enabled = false;
		vars->player_u1->enabled = false;
		vars->player_d1->enabled = false;
		vars->player_l2->enabled = false;
		vars->player_u2->enabled = false;
		vars->player_d2->enabled = false;
	}
	else
		run_img_falser_helper(vars, direction);
}

void	run_animation(t_vars *vars, int direction)
{
	vars->player->enabled = false;
	if (direction == 1)
	{
		run_img_falser(vars, 1);
		run_process(vars, vars->player_l1, vars->player_l2);
	}
	else if (direction == 2)
	{
		run_img_falser(vars, 2);
		run_process(vars, vars->player_r1, vars->player_r2);
	}
	else if (direction == 3)
	{
		run_img_falser(vars, 3);
		run_process(vars, vars->player_u1, vars->player_u2);
	}
	else if (direction == 4)
	{
		run_img_falser(vars, 4);
		run_process(vars, vars->player_d1, vars->player_d2);
	}
}
