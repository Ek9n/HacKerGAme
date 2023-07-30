/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:09:56 by hstein            #+#    #+#             */
/*   Updated: 2023/07/29 12:44:13 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	check_hitbox_enemy(mlx_image_t *img1, mlx_image_t *img2, \
		int x_off, int y_off)
{
	int	i;

	i = img2->count - 1;
	while (i-- >= 0)
	{
		if (((img1->instances[0].x + x_off) < \
			img2->instances[i].x + IMGSIZE) && \
			((img1->instances[0].x + x_off + IMGSIZE) > \
			img2->instances[i].x) && \
			((img1->instances[0].y + y_off) < \
			img2->instances[i].y + IMGSIZE) && \
			((img1->instances[0].y + y_off + IMGSIZE) > \
			img2->instances[i].y))
		{
			return (1);
		}
	}
	return (0);
}

int	check_hitbox_enemy2(mlx_instance_t *inst1, mlx_image_t *img2, \
		int x_off, int y_off)
{
	int	i;

	i = img2->count - 1;
	while (i-- >= 0)
	{
		if (((inst1->x + x_off) < img2->instances[i].x + IMGSIZE) && \
			((inst1->x + x_off + IMGSIZE) > img2->instances[i].x) && \
			((inst1->y + y_off) < img2->instances[i].y + IMGSIZE) && \
			((inst1->y + y_off + IMGSIZE) > img2->instances[i].y))
		{
			return (1);
		}
	}
	return (0);
}

int	check_hitbox_enemytoenemy(mlx_image_t *img, \
		size_t n, int x_off, int y_off)
{
	size_t	i;

	i = 0;
	while (i < img->count)
	{
		if (i != n)
			if (((img->instances[i].x + x_off) < \
				img->instances[n].x + IMGSIZE) && \
				((img->instances[i].x + x_off + IMGSIZE) > \
				img->instances[n].x) && \
				((img->instances[i].y + y_off) < \
				img->instances[n].y + IMGSIZE) && \
				((img->instances[i].y + y_off + IMGSIZE) > \
				img->instances[n].y))
				return (1);
		i++;
	}
	return (0);
}

int	check_hitbox_instances(mlx_image_t *img, \
		mlx_instance_t *instance, int x_off, int y_off)
{
	size_t	i;

	i = 0;
	while (i < img->count)
	{
		if (((img->instances[i].x + x_off) < instance->x + IMGSIZE) && \
			((img->instances[i].x + x_off + IMGSIZE) > instance->x) && \
			((img->instances[i].y + y_off) < instance->y + IMGSIZE) && \
			((img->instances[i].y + y_off + IMGSIZE) > instance->y))
			return (1);
		i++;
	}
	return (0);
}

void	switchimg(t_vars *vars)
{
	static bool			flag;
	int					delay;
	static int			img_num;

	delay = 50;
	if (remote_delay_ms(delay))
		flag = true;
	if (flag == true && !remote_delay_ms(delay))
	{
		vars->enemy->enabled = false;
		vars->enemy2->enabled = false;
		vars->enemy3->enabled = false;
		if (img_num == 0)
			vars->enemy->enabled = true;
		else if (img_num == 1)
			vars->enemy2->enabled = true;
		else if (img_num == 2)
			vars->enemy3->enabled = true;
		img_num++;
		if (img_num > 2)
			img_num = 0;
		flag = false;
	}
}
