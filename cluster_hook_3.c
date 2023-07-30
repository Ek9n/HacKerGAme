/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_hook_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 19:36:16 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
static size_t	delay_server_ms(void)
{
	static bool		flag;
	static size_t	counter;
	size_t			delay;

	delay = 10;
	if (remote_delay_ms(delay))
		flag = true;
	if (flag == true && !remote_delay_ms(delay))
	{
		counter += 50;
		flag = false;
	}
	return (counter);
}

static void	server_light_off(t_vars *vars)
{
	unsigned int	size_xy[2];
	unsigned int	offset_xy[2];

	size_xy[0] = 7;
	size_xy[1] = 8;
	offset_xy[0] = 22;
	offset_xy[1] = 1;
	print_square(vars, vars->black, size_xy, offset_xy);
	mlx_image_to_window(vars->mlx, vars->black_trans, 22 * IMGSIZE, IMGSIZE);
}

void	hack_server(t_vars *vars)
{
	if (check_hitbox_2(vars, vars->server_point->instances[0], 0, 0) && \
			vars->server_flag == true)
	{
		ma_sound_start(&vars->sound.keyboard);
		if (delay_server_ms() > 1000)
		{
			vars->server_flag = false;
			ma_sound_stop(&vars->sound.keyboard);
			ma_sound_stop(&vars->sound.server);
			ma_sound_start(&vars->sound.server_access);
			ma_sound_start(&vars->sound.heartbeat);
			server_light_off(vars);
			vars->randenemy_option = 2;
		}
	}
	else if (!check_hitbox_2(vars, vars->server_point->instances[0], 0, 0))
		ma_sound_stop(&vars->sound.keyboard);
}
