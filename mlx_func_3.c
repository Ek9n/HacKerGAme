/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:30:40 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 21:32:26 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	search_darkview_helper(t_vars *vars, \
	mlx_image_t *image, int direction, int i)
{
	if (image->instances[i].x == vars->player->instances[0].x && \
			image->instances[i].y == vars->player->instances[0].y)
		vars->black->instances[i].enabled = 0;
	if (direction == 1 && (image->instances[i].x == \
			vars->player->instances[0].x - IMGSIZE && \
			image->instances[i].y == vars->player->instances[0].y))
		vars->black->instances[i].enabled = 0;
	if (direction == 2 && (image->instances[i].x == \
			vars->player->instances[0].x + IMGSIZE && \
			image->instances[i].y == vars->player->instances[0].y))
		vars->black->instances[i].enabled = 0;
	if (direction == 3 && (image->instances[i].x == \
			vars->player->instances[0].x && image->instances[i].y == \
			vars->player->instances[0].y - IMGSIZE))
		vars->black->instances[i].enabled = 0;
	if (direction == 4 && (image->instances[i].x == \
			vars->player->instances[0].x && image->instances[i].y == \
			vars->player->instances[0].y + IMGSIZE))
		vars->black->instances[i].enabled = 0;
}

int	checker_wall(t_vars *vars, mlx_image_t *pic, int i, int direction)
{
	int		xs;
	int		ys;
	char	*itoa;

	xs = pic->instances[i].x / IMGSIZE;
	ys = pic->instances[i].y / IMGSIZE;
	if (direction == 1 && vars->map[ys - 1][xs] == '1')
		return (1);
	if (direction == 2 && vars->map[ys + 1][xs] == '1')
		return (1);
	if (direction == 3 && vars->map[ys][xs - 1] == '1')
		return (1);
	if (direction == 4 && vars->map[ys][xs + 1] == '1')
		return (1);
	if (pic == vars->player && vars->win_lose_flag == 0)
		ft_printf("steps %d\n", ++vars->steps);
	if (vars->mlx_outputstring != NULL)
		mlx_delete_image(vars->mlx, vars->mlx_outputstring);
	itoa = ft_itoa(vars->steps);
	vars->mlx_outputstring = mlx_put_string(vars->mlx, itoa, 0, 0);
	free(itoa);
	return (0);
}
