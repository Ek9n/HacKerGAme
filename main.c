/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:54:30 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/30 00:06:29 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_so_long_init(t_vars *vars, int i)
{
	vars->size_y = i;
	vars->size_x = ft_strlen(vars->map[0]);
}

int	terminate(t_vars *vars, int ret)
{
	if (ret)
	{
		ft_printf("Error\n(terminate)\n");
		mlx_terminate(vars->mlx);
		ft_free(vars->map);
		return (1);
	}
	return (0);
}

static int	setup_helper(t_vars *vars)
{
	mlx_set_window_pos(vars->mlx, 0, 0);
	if (img_handling(vars))
		return (1);
	if (vars->cluster_flag)
		setup_cluster(vars);
	mlx_loop_hook(vars->mlx, ft_hook, vars);
	mlx_loop_hook(vars->mlx, ft_hook3, vars);
	mlx_loop(vars->mlx);
	mlx_terminate(vars->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	static t_vars	vars;

	if (start_and_error(argc, argv, &vars))
		return (0);
	if (!ft_strncmp(argv[1], "maps/cluster6a.ber", ft_strlen(argv[1])))
	{
		init_prestory(&vars);
		vars.cluster_flag = true;
		setup_cluster_mlx();
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_set_setting(MLX_MAXIMIZED, 0);
	vars.mlx = mlx_init(vars.size_x * IMGSIZE, \
		vars.size_y * IMGSIZE, "SO_LONG", true);
	if (!(vars.mlx))
		return (EXIT_FAILURE);
	if (setup_helper(&vars) == 1)
		return (1);
	if (vars.win_lose_flag == 1 || vars.win_lose_flag == 2)
		init_endscreen(&vars);
	if (vars.cluster_flag)
		terminate_cluster_sound(&vars);
	ft_free(vars.map);
	return (0);
}
