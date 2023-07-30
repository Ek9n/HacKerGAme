/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 18:19:02 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
static void	print_square_helper(t_vars *vars, mlx_image_t *img, \
		unsigned int size_xy[2], unsigned int offset_xy[2])
{
	unsigned int	tmp_xn;
	unsigned int	tmp_yn;
	unsigned int	x;
	unsigned int	y;

	offset_xy[0] *= IMGSIZE;
	offset_xy[1] *= IMGSIZE;
	tmp_xn = size_xy[0];
	tmp_yn = size_xy[1];
	x = 0;
	y = 0;
	while (tmp_yn--)
	{
		while (tmp_xn--)
		{
			mlx_image_to_window(vars->mlx, img,
				(x * IMGSIZE) + offset_xy[0], (y * IMGSIZE) + offset_xy[1]);
			x++;
		}
		tmp_xn = size_xy[0];
		x = 0;
		y++;
	}
}

int	print_square(t_vars *vars, mlx_image_t *img, \
		unsigned int size_xy[2], unsigned int offset_xy[2])
{
	bool	flag_malloc;

	flag_malloc = false;
	if (!size_xy)
	{
		write(2, "(print_square): No valid size.\n", 31);
		return (1);
	}
	else
	{
		if (!offset_xy)
		{
			offset_xy = malloc(2 * sizeof(unsigned int));
			offset_xy[0] = 0;
			offset_xy[1] = 0;
			flag_malloc = true;
		}
		print_square_helper(vars, img, size_xy, offset_xy);
		if (flag_malloc)
			free(offset_xy);
	}
	return (0);
}

void	light_scene2_helper(t_vars *vars, const int i)
{
	if (i == 0)
	{
		vars->red_trans->enabled = true;
		vars->green_trans->enabled = false;
		vars->purple_trans->enabled = false;
	}
	else if (i == 1)
	{
		vars->red_trans->enabled = false;
		vars->green_trans->enabled = true;
		vars->purple_trans->enabled = false;
	}
	else if (i == 2)
	{
		vars->red_trans->enabled = false;
		vars->green_trans->enabled = false;
		vars->purple_trans->enabled = true;
	}
}

void	light_scene2(t_vars *vars, int frequence)
{
	static int		i;
	static int		delay_state;
	int				delay;
	unsigned int	size_xy[2];

	size_xy[0] = vars->size_x;
	size_xy[1] = vars->size_y;
	if (vars->red_trans->count == 0)
	{
		print_square(vars, vars->red_trans, size_xy, NULL);
		print_square(vars, vars->green_trans, size_xy, NULL);
		print_square(vars, vars->purple_trans, size_xy, NULL);
	}
	delay = remote_delay_ms(frequence);
	if (delay_state != delay)
		i++;
	light_scene2_helper(vars, i);
	if (i > 2)
		i = 0;
	delay_state = delay;
}
