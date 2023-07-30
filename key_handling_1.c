/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 00:46:09 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 18:07:16 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	key_handler(t_vars *vars, int step, \
	size_t *tmp_steps, int *last_dir)
{
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
		key_handling_helper_0(vars, step, tmp_steps, last_dir);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
		key_handling_helper_1(vars, step, tmp_steps, last_dir);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_UP))
		key_handling_helper_2(vars, step, tmp_steps, last_dir);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_DOWN))
		key_handling_helper_3(vars, step, tmp_steps, last_dir);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
}

void	key_handling(t_vars *vars)
{
	int				step;
	static size_t	tmp_steps;
	static int		last_dir;

	step = 4;
	if (!vars->stop_flag)
		key_handler(vars, step, &tmp_steps, &last_dir);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	vars->steps = tmp_steps / IMGSIZE;
}
