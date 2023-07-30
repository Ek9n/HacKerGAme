/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:28:15 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/30 00:08:54 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	win_lose_func(t_vars *vars)
{
	if (vars->win_lose_flag == 1)
	{
		mlx_resize_image(vars->lost, 900, 150);
		mlx_image_to_window(vars->mlx, vars->lost, 0, 0);
		mlx_loop_hook(vars->mlx, ft_hook2, vars);
		mlx_loop(vars->mlx);
		mlx_terminate(vars->mlx);
	}
	if (vars->win_lose_flag == 2)
	{
		mlx_resize_image(vars->won, 900, 150);
		mlx_image_to_window(vars->mlx, vars->won, 0, 0);
		mlx_loop_hook(vars->mlx, ft_hook2, vars);
		mlx_loop(vars->mlx);
		mlx_terminate(vars->mlx);
	}
}

int	init_endscreen(t_vars *vars)
{
	mlx_set_setting(MLX_MAXIMIZED, 0);
	vars->mlx = mlx_init(900, 150, "SO_LONG", true);
	mlx_set_window_pos(vars->mlx, 100, 100);
	vars->lost = source_to_mlx_image_t(vars, "./pictures/lost00.png");
	vars->won = source_to_mlx_image_t(vars, "./pictures/won00.png");
	if (vars->lost == NULL || vars->won == NULL)
	{
		mlx_terminate(vars->mlx);
		return (1);
	}
	win_lose_func(vars);
	return (0);
}

int	init_prestory(t_vars *vars)
{
	vars->mlx = mlx_init(1920, 980, "SO_LONG", true);
	mlx_set_window_pos(vars->mlx, 0, 0);
	vars->prestory = source_to_mlx_image_t(vars, \
		"./pictures/prestory.png");
	if (vars->prestory == NULL)
		return (1);
	mlx_image_to_window(vars->mlx, vars->prestory, 0, 0);
	mlx_loop_hook(vars->mlx, ft_hook2, vars);
	mlx_loop(vars->mlx);
	mlx_terminate(vars->mlx);
	return (0);
}