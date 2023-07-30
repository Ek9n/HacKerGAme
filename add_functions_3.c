/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 19:52:08 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
void	print_colls(t_vars *vars)
{
	char	*output;
	char	*c_cnt;

	c_cnt = ft_itoa(vars->c_ctr);
	output = ft_strjoin("COLLECTIBLES LEFT: ", c_cnt);
	if (vars->mlx_outputstring)
		mlx_delete_image(vars->mlx, vars->mlx_outputstring);
	vars->mlx_outputstring = mlx_put_string(vars->mlx, output, \
		(14 + IMGSIZE * 2) + (vars->size_x / 2) * IMGSIZE - 3 * IMGSIZE -10, \
		vars->size_y * IMGSIZE - IMGSIZE + 12);
	set_image_depth(vars->mlx_outputstring, 10);
	free(output);
	free(c_cnt);
}

void	print_steps(t_vars *vars)
{
	char	*steps;
	char	*output;

	steps = ft_itoa(vars->steps);
	output = ft_strjoin("STEPS: ", steps);
	if (vars->mlx_outputstring2)
		mlx_delete_image(vars->mlx, vars->mlx_outputstring2);
	vars->mlx_outputstring2 = mlx_put_string(vars->mlx, output, \
		14 + (vars->size_x / 2) * IMGSIZE - 3 * IMGSIZE, \
		vars->size_y * IMGSIZE - IMGSIZE + 12);
	set_image_depth(vars->mlx_outputstring2, 11);
	free(steps);
	free(output);
}

void	print_time(t_vars *vars)
{
	static bool		flag;
	static size_t	secs;
	int				delay;
	char			*time;
	char			*output;

	time = ft_itoa(secs / 10);
	output = ft_strjoin(" TIME: ", time);
	delay = 50;
	if (remote_delay_ms(delay))
		flag = true;
	if (flag == true && !remote_delay_ms(delay))
	{
		secs++;
		if (vars->mlx_outputstring3)
			mlx_delete_image(vars->mlx, vars->mlx_outputstring3);
		vars->mlx_outputstring3 = \
			mlx_put_string(vars->mlx, output, 14 + (vars->size_x / 2) * \
			IMGSIZE - 3 * IMGSIZE, vars->size_y * IMGSIZE - IMGSIZE + 30);
		set_image_depth(vars->mlx_outputstring3, 12);
		flag = false;
	}
	free(time);
	free(output);
}

void	print_some_cool(t_vars *vars)
{
	mlx_image_to_window(vars->mlx, vars->tablet, (vars->size_x / 2) * \
		IMGSIZE - 3 * IMGSIZE, vars->size_y * IMGSIZE - IMGSIZE);
	set_image_depth(vars->tablet, L_SOME);
	mlx_image_to_window(vars->mlx, vars->deadguy0, 0, 0);
	mlx_image_to_window(vars->mlx, vars->deadguy1, 0, 0);
	mlx_image_to_window(vars->mlx, vars->deadguy2, 0, 0);
	mlx_image_to_window(vars->mlx, vars->blood0, 0, 0);
	mlx_image_to_window(vars->mlx, vars->blood1, 0, 0);
	mlx_image_to_window(vars->mlx, vars->blood2, 0, 0);
	set_image_depth(vars->deadguy0, L_DEATH);
	set_image_depth(vars->deadguy1, L_DEATH);
	set_image_depth(vars->deadguy2, L_DEATH);
	set_image_depth(vars->blood0, L_BLOOD2);
	set_image_depth(vars->blood1, L_BLOOD3);
	set_image_depth(vars->blood2, L_BLOOD1);
	vars->deadguy0->enabled = false;
	vars->deadguy1->enabled = false;
	vars->deadguy2->enabled = false;
	vars->blood0->enabled = false;
	vars->blood1->enabled = false;
	vars->blood2->enabled = false;
}
