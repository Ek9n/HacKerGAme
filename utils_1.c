/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:25:43 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 21:13:09 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	check_lines(char *joined)
{
	int	i;

	i = -1;
	while (joined[++i])
		if (joined[i] == '\n' && joined[i + 1] == '\n')
			return (1);
	return (0);
}

int	cnt_maplines(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	win_func(t_vars *vars)
{
	vars->win_lose_flag = 2;
	ft_putstr_fd("You won!\n", 1);
	mlx_close_window(vars->mlx);
}

void	lose_func(t_vars *vars)
{
	vars->win_lose_flag = 1;
	ft_putstr_fd("You lost!\n", 1);
	mlx_close_window(vars->mlx);
}
