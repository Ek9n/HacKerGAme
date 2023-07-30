/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:54:42 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/29 19:51:31 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	my_key_func2(mlx_key_data_t keydata, void *bla)
{
	t_vars	*vars;

	vars = bla;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(vars->mlx);
}

void	ft_hook2(void *vars)
{
	mlx_key_hook(((t_vars *)vars)->mlx, &my_key_func2, vars);
}

void	ft_hook(void *params)
{
	t_vars	*vars;

	vars = (t_vars *)params;
	print_steps(vars);
	print_time(vars);
	print_colls(vars);
	if (vars->win_lose_flag && delay_ms() > 1000)
		lose_func(vars);
	if (vars->c_ctr == 0 && \
		vars->server_flag == false && \
		check_hitbox_2(vars, vars->openexit->instances[0], \
		15 - IMGSIZE, 15 - IMGSIZE))
	{
		vars->stop_flag = 1;
		while (delay_ms() < 1000)
		{
		}
		win_func(vars);
	}
}

static void	randenemy_sequence(t_vars *vars)
{
	static bool	randemy_flag;
	static int	action_cnt;

	if (vars->randenemy_option != 0)
		randenemy4(vars, vars->randenemy_option);
	else if (action_cnt == 0)
		action_cnt = vars->c_ctr;
	else if (!randemy_flag)
	{
		randenemy4(vars, 0);
		if ((action_cnt - vars->c_ctr) >= 9)
			randemy_flag = true;
	}
	else if (randemy_flag)
		randenemy4(vars, 1);
}

void	ft_hook3(void *param)
{
	t_vars		*vars;

	vars = (t_vars *)param;
	key_handling(vars);
	search_field_2_hitbox(vars, vars->black);
	check_for_collectible(vars);
	if (vars->cluster_flag)
		cluster_hook(vars);
	randenemy_sequence(vars);
}
