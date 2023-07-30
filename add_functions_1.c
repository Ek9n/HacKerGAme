/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:56:23 by hstein            #+#    #+#             */
/*   Updated: 2023/07/26 18:37:03 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

//Enviroment FUN-Functions
int	remote_delay_ms(size_t delay)
{
	size_t			time_us;
	static size_t	time_tmp;
	static size_t	time_cnt;
	struct timeval	tv;

	delay *= 1000;
	gettimeofday(&tv, NULL);
	time_us = tv.tv_usec;
	if (time_tmp > time_us)
		time_cnt += 1000000 - time_tmp + time_us;
	else
		time_cnt += time_us - time_tmp;
	time_tmp = time_us;
	if ((time_cnt % (delay * 2)) < delay)
		return (1);
	return (0);
}

size_t	delay_ms(void)
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

int	check_hitbox_fog(t_vars *vars, mlx_instance_t instance)
{
	if ((vars->player->instances[0].x - (IMGSIZE / 2) < instance.x + IMGSIZE) \
		&& (vars->player->instances[0].x + (IMGSIZE / 2) + IMGSIZE \
			> instance.x) \
		&& (vars->player->instances[0].y - (IMGSIZE / 2) \
			< instance.y + IMGSIZE) && \
		(vars->player->instances[0].y + (IMGSIZE / 2) + IMGSIZE \
			> instance.y))
		return (1);
	return (0);
}

void	search_field_2_hitbox(t_vars *vars, mlx_image_t *image)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		if (check_hitbox_fog(vars, image->instances[i]))
			image->instances[i].enabled = 0;
		else
			image->instances[i].enabled = 1;
		i++;
	}
}

int	check_hitbox(t_vars *vars, mlx_instance_t instance, int x_off, int y_off)
{
	if (((vars->player->instances[0].x + x_off) < instance.x + IMGSIZE) && \
		((vars->player->instances[0].x + x_off + IMGSIZE) > instance.x) && \
		((vars->player->instances[0].y + y_off) < instance.y + IMGSIZE) && \
		((vars->player->instances[0].y + y_off + IMGSIZE) > instance.y))
		return (1);
	return (0);
}
