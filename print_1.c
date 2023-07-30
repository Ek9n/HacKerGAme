/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:06:30 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/29 20:22:54 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	img_handling(t_vars *vars)
{
	if (terminate(vars, pics_init_zero(vars)) || \
			terminate(vars, pics_init_two(vars)) || \
			terminate(vars, pics_init_three(vars)) || \
			terminate(vars, pics_init_four(vars)) || \
			terminate(vars, !print_map(vars)))
		return (1);
	print_some_cool(vars);
	spawn_player_imgs(vars);
	set_depth(vars);
	return (0);
}

int	setting_ctrs(t_vars *vars, int j, int k, char c)
{
	if (c != 'P' && c != 'C' && c != 'E' && c != 'X' && c != '0' && c != '1')
		return (0);
	else if (c == 'P')
	{
		vars->p_ctr++;
		vars->start.x = j;
		vars->start.y = k;
	}
	else if (c == 'C')
		vars->c_ctr++;
	else if (c == 'E')
	{
		vars->e_ctr++;
		vars->exit.x = j;
		vars->exit.y = k;
	}
	else if (c == 'X')
		vars->x_ctr++;
	return (1);
}

int	print_ground(t_vars *vars)
{
	int	xs;
	int	ys;

	ys = -1;
	while (++ys < vars->size_y)
	{
		xs = -1;
		while (++xs < vars->size_x)
			if (mlx_image_to_window(vars->mlx, vars->ground, \
				xs * IMGSIZE, ys * IMGSIZE) == -1)
				return (0);
	}
	return (1);
}

int	print_c_p(t_vars *vars, int xs, int ys)
{
	int	img_x;
	int	img_y;

	img_x = xs * IMGSIZE;
	img_y = ys * IMGSIZE;
	if (vars->map[ys][xs] == 'C')
	{
		if (mlx_image_to_window(vars->mlx, vars->coll, img_x, img_y) == -1)
			return (0);
	}
	else if (vars->map[ys][xs] == 'P')
	{
		if (mlx_image_to_window(vars->mlx, vars->player, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->player_r1, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->player_l1, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->player_u1, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->player_d1, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->player_r2, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->player_l2, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->player_u2, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->player_d2, img_x, img_y) == -1)
			return (0);
	}
	return (1);
}

int	print_img(t_vars *vars, int xs, int ys)
{
	int	img_x;
	int	img_y;

	img_x = xs * IMGSIZE;
	img_y = ys * IMGSIZE;
	if (vars->map[ys][xs] == '1')
	{
		if (mlx_image_to_window(vars->mlx, vars->wall, img_x, img_y) == -1)
			return (0);
	}
	else if (vars->map[ys][xs] == 'C' || vars->map[ys][xs] == 'P')
	{
		if (!print_c_p(vars, xs, ys))
			return (0);
	}
	else if (vars->map[ys][xs] == 'E')
	{
		if ((mlx_image_to_window(vars->mlx, vars->openexit, img_x, img_y) == -1 \
		|| mlx_image_to_window(vars->mlx, vars->gameexit, img_x, img_y) == -1))
			return (0);
	}
	else if (vars->map[ys][xs] == 'X')
		if (mlx_image_to_window(vars->mlx, vars->enemy, img_x, img_y) == -1)
			return (0);
	return (1);
}
