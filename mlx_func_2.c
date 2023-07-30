/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:54:42 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/29 19:50:47 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	check_for_walls(t_vars *vars, int x_off, int y_off)
{
	size_t	i;

	i = 0;
	while (i < vars->wall->count)
	{
		if (check_hitbox(vars, vars->wall->instances[i], x_off, y_off))
			return (1);
		i++;
	}
	return (0);
}

void	change_collectibles(t_vars *vars, mlx_instance_t *a)
{
	static unsigned int	cnt;

	a->enabled = false;
	mlx_image_to_window(vars->mlx, vars->coll2, a->x, a->y);
	mlx_set_instance_depth(&vars->coll2->instances[cnt], L_COLLECTIBLE);
	cnt++;
}

void	check_for_collectible(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->coll->count)
	{
		if (check_hitbox_2(vars, vars->coll->instances[i], 0, 0) && \
			vars->coll->instances[i].enabled == true)
		{
			ma_sound_start(&vars->sound.hacking00);
			change_collectibles(vars, &vars->coll->instances[i]);
			vars->c_ctr--;
			if (vars->c_ctr == 0)
			{
				vars->gameexit->instances[0].enabled = false;
				vars->openexit->instances[0].enabled = true;
			}
		}
		i++;
	}
}

int	check_for_exit(t_vars *vars)
{
	if (check_hitbox(vars, vars->openexit->instances[0], 0, 0))
		return (1);
	return (0);
}

int	check_hitbox_2(t_vars *vars, mlx_instance_t instance, int x_off, int y_off)
{
	if (((vars->player->instances[0].x + IMGSIZE + x_off) > instance.x) && \
		((vars->player->instances[0].x - x_off) < instance.x + IMGSIZE) && \
		((vars->player->instances[0].y + IMGSIZE + y_off) > instance.y) && \
		((vars->player->instances[0].y - y_off) < instance.y + IMGSIZE))
		return (1);
	return (0);
}
