/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:57:05 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 05:53:44 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
int	search_through_instances(t_vars *vars, mlx_image_t *image)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		if (check_hitbox(vars, image->instances[i], 0, 0) && \
				image->instances[i].z == L_ENEMY)
			return (i);
		i++;
	}
	return (-1);
}

int	search_through_instances2(t_vars *vars, mlx_image_t *image)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		if (check_hitbox(vars, image->instances[i], 0, 0) && \
				(image->instances[i].z == L_ENEMY))
			return (i);
		i++;
	}
	return (-1);
}

int	search_through_instances3(t_vars *vars, mlx_image_t *image, \
		int x_off, int y_off)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		if (check_hitbox_2(vars, image->instances[i], x_off, y_off) \
			&& image->enabled)
			return (0);
		i++;
	}
	return (1);
}

static void	darkview_helper(t_vars *vars, mlx_image_t *image, \
	int direction, size_t i)
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

void	search_darkview(t_vars *vars, mlx_image_t *image, int direction)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		image->instances[i].enabled = 1;
		i++;
	}
	i = 0;
	while (i < image->count)
	{
		darkview_helper(vars, image, direction, i);
		i++;
	}
}
