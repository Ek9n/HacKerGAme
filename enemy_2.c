/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:09:56 by hstein            #+#    #+#             */
/*   Updated: 2023/07/28 04:08:09 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	spawnimgs(t_vars *vars)
{
	while (vars->enemy2->count < vars->enemy->count)
	{
		mlx_image_to_window(vars->mlx, vars->enemy2, 0, 0);
		mlx_image_to_window(vars->mlx, vars->enemy3, 0, 0);
		vars->enemy2->enabled = false;
		vars->enemy3->enabled = false;
	}
}

void	setimgs(t_vars *vars, mlx_image_t *img)
{
	size_t	i;

	i = 0;
	while (i < vars->enemy->count)
	{
		img->instances[i].x = vars->enemy->instances[i].x;
		img->instances[i].y = vars->enemy->instances[i].y;
		mlx_set_instance_depth(&img->instances[i], vars->enemy->instances[i].z);
		i++;
	}
}

void	movevertical(t_vars *vars, mlx_instance_t *enemy_instance, size_t n)
{
	static bool	direction[999];

	if ((!check_hitbox_instances(vars->wall, enemy_instance, 0, -1) && \
			direction[n] == 0) && \
			!check_hitbox_instances(vars->coll, enemy_instance, 0, -1) && \
			!check_hitbox_instances(vars->gameexit, enemy_instance, 0, -1) && \
			!check_hitbox_enemytoenemy(vars->enemy, n, 0, -1))
		enemy_instance->y += IMGSIZE / 8;
	else
		direction[n] = 1;
	if ((!check_hitbox_instances(vars->wall, enemy_instance, 0, 1) && \
			direction[n] == 1) && \
			!check_hitbox_instances(vars->coll, enemy_instance, 0, 1) && \
			!check_hitbox_instances(vars->gameexit, enemy_instance, 0, 1) && \
			!check_hitbox_enemytoenemy(vars->enemy, n, 0, 1))
		enemy_instance->y -= IMGSIZE / 8;
	else
		direction[n] = 0;
}

void	movehorizontical(t_vars *vars, mlx_instance_t *enemy_instance, size_t n)
{
	static bool	direction[999];

	if (!check_hitbox_instances(vars->wall, enemy_instance, -1, 0) && \
			direction[n] == 0 && \
			!check_hitbox_instances(vars->coll, enemy_instance, -1, 0) && \
			!check_hitbox_instances(vars->gameexit, enemy_instance, -1, 0) && \
			!check_hitbox_enemytoenemy(vars->enemy, n, -1, 0))
		enemy_instance->x += IMGSIZE / 8;
	else
		direction[n] = 1;
	if (!check_hitbox_instances(vars->wall, enemy_instance, 1, 0) && \
			direction[n] == 1 && \
			!check_hitbox_instances(vars->coll, enemy_instance, 1, 0) && \
			!check_hitbox_instances(vars->gameexit, enemy_instance, 1, 0) && \
			!check_hitbox_enemytoenemy(vars->enemy, n, 1, 0))
		enemy_instance->x -= IMGSIZE / 8;
	else
		direction[n] = 0;
}

void	randenemy3(t_vars *vars, int option)
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
				movevertical(vars, &vars->enemy->instances[i], i);
				if (option == 1)
					movehorizontical(vars, &vars->enemy->instances[i], i);
				i++;
			}
			flag = false;
		}
	}
}
