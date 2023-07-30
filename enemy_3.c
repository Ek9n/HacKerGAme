/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:09:56 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 13:56:01 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	movevertical2(t_vars *vars, mlx_instance_t *enemy_instance, size_t n)
{
	static bool	direction[999];

	if ((!check_hitbox_instances(vars->wall, enemy_instance, 0, 1) && \
			direction[n] == 0) && \
			!check_hitbox_instances(vars->coll, enemy_instance, 0, 1) && \
			!check_hitbox_instances(vars->gameexit, enemy_instance, 0, 1) && \
			!check_hitbox_enemytoenemy(vars->enemy, n, 0, 1))
		enemy_instance->y -= IMGSIZE / 8;
	else
		direction[n] = 1;
	if ((!check_hitbox_instances(vars->wall, enemy_instance, 0, -1) && \
			direction[n] == 1) && \
			!check_hitbox_instances(vars->coll, enemy_instance, 0, -1) && \
			!check_hitbox_instances(vars->gameexit, enemy_instance, 0, -1) && \
			!check_hitbox_enemytoenemy(vars->enemy, n, 0, -1))
		enemy_instance->y += IMGSIZE / 8;
	else
		direction[n] = 0;
}

void	movehorizontical2(t_vars *vars, \
			mlx_instance_t *enemy_instance, size_t n)
{
	static bool	direction[999];

	if (!check_hitbox_instances(vars->wall, enemy_instance, -1, 0) && \
			direction[n] == 1 && \
			!check_hitbox_instances(vars->coll, enemy_instance, -1, 0) && \
			!check_hitbox_instances(vars->gameexit, enemy_instance, -1, 0) && \
			!check_hitbox_enemytoenemy(vars->enemy, n, -1, 0))
		enemy_instance->x += IMGSIZE / 8;
	else
		direction[n] = 0;
	if (!check_hitbox_instances(vars->wall, enemy_instance, 1, 0) && \
			direction[n] == 0 && \
			!check_hitbox_instances(vars->coll, enemy_instance, 1, 0) && \
			!check_hitbox_instances(vars->gameexit, enemy_instance, 1, 0) && \
			!check_hitbox_enemytoenemy(vars->enemy, n, 1, 0))
		enemy_instance->x -= IMGSIZE / 8;
	else
		direction[n] = 1;
}

static void	randenemy4_helper(t_vars *vars, mlx_instance_t *img_instance, \
				int option, size_t i)
{
	if (option == 1)
		movevertical2(vars, img_instance, i);
	else if (option == 3)
	{
		movevertical2(vars, img_instance, i);
		movehorizontical2(vars, img_instance, i);
	}
	else if (option == 2)
		movehorizontical2(vars, img_instance, i);
}

void	randenemy4(t_vars *vars, int option)
{
	static bool	flag;
	int			delay;
	size_t		i;

	randenemy_presetup(vars);
	i = 0;
	delay = 36;
	if (!vars->stop_flag)
	{
		if (remote_delay_ms(delay))
			flag = true;
		if (flag == true && !remote_delay_ms(delay))
		{
			while (i < vars->enemy->count)
			{
				randenemy4_helper(vars, &vars->enemy->instances[i], option, i);
				i++;
			}
			flag = false;
		}
	}
}

void	randenemy_presetup(t_vars *vars)
{
	spawnimgs(vars);
	setimgs(vars, vars->enemy2);
	setimgs(vars, vars->enemy3);
	switchimg(vars);
	if (!search_through_instances3(vars, vars->enemy, -15, -15) || \
		!search_through_instances3(vars, vars->enemy2, -15, -15) || \
		!search_through_instances3(vars, vars->enemy3, -15, -15))
	{
		vars->stop_flag = 1;
		vars->win_lose_flag = 1;
		kill_sound(vars, 0);
		death_animation(vars);
	}
}
