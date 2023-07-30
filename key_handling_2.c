/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:46:09 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 18:10:14 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	key_handling_helper_3(t_vars *vars, int step, \
	size_t *tmp_steps, int *last_dir)
{
	if (mlx_is_key_down(vars->mlx, MLX_KEY_DOWN))
	{
		vars->player->instances[0].y += step;
		if (!search_through_instances3(vars, vars->wall, -10, -10) || \
				!search_through_instances3(vars, vars->coll, -10, -10) || \
				!search_through_instances3(vars, vars->coll2, -10, -10))
			vars->player->instances[0].y -= step;
		else
			*tmp_steps += step;
		run_animation(vars, 4);
		*last_dir = 4;
	}
}

void	key_handling_helper_2(t_vars *vars, int step, \
	size_t *tmp_steps, int *last_dir)
{
	if (mlx_is_key_down(vars->mlx, MLX_KEY_UP))
	{
		vars->player->instances[0].y -= step;
		if (!search_through_instances3(vars, vars->wall, -10, -10) || \
				!search_through_instances3(vars, vars->coll, -10, -10) || \
				!search_through_instances3(vars, vars->coll2, -10, -10))
			vars->player->instances[0].y += step;
		else
			*tmp_steps += step;
		run_animation(vars, 3);
		*last_dir = 3;
	}
}

void	key_handling_helper_1(t_vars *vars, int step, \
	size_t *tmp_steps, int *last_dir)
{
	vars->player->instances[0].x += step;
	if (!search_through_instances3(vars, vars->wall, -10, -10) || \
			!search_through_instances3(vars, vars->coll, -10, -10) || \
			!search_through_instances3(vars, vars->coll2, -10, -10) || \
			(!search_through_instances3(vars, \
			vars->tresor_door_closed, -20, -20) && \
			vars->tresor_door_closed->instances[0].enabled == true))
		vars->player->instances[0].x -= step;
	else
		*tmp_steps += step;
	run_animation(vars, 2);
	*last_dir = 2;
}

void	key_handling_helper_0(t_vars *vars, int step, \
	size_t *tmp_steps, int *last_dir)
{
	vars->player->instances[0].x -= step;
	if (!search_through_instances3(vars, vars->wall, -10, -10) || \
			!search_through_instances3(vars, vars->coll, -10, -10) || \
			!search_through_instances3(vars, vars->coll2, -10, -10) || \
			(!search_through_instances3(vars, \
			vars->tresor_door_closed, -20, -20) && \
			vars->tresor_door_closed->instances[0].enabled == true))
		vars->player->instances[0].x += step;
	else
		*tmp_steps += step;
	run_animation(vars, 1);
	*last_dir = 1;
}
