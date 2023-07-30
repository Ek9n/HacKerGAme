/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pics_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:22:40 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/29 20:18:07 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

mlx_image_t	*source_to_mlx_image_t(t_vars *vars, char *adress)
{
	mlx_texture_t	*tmp;
	mlx_image_t		*img;

	tmp = mlx_load_png(adress);
	if (!tmp)
		return (NULL);
	img = mlx_texture_to_image(vars->mlx, tmp);
	if (!img)
		return (NULL);
	mlx_delete_texture(tmp);
	return (img);
}

int	start_and_error(int argc, char **argv, t_vars *vars)
{
	int		i;
	char	*joined;
	char	**split;

	i = 0;
	if (argc != 2)
		return (ft_error_sl("Error\nInvalid arguments (start_and_error)\n"));
	if (!check_suffix(argv[1]))
		return (ft_error_sl("Error\nInvalid map (start_and_error)\n"));
	joined = read_file(argv[1], &i);
	if (joined == NULL || check_lines(joined))
		return (ft_error_sl("Error\nWhile reading (start_and_error)\n"));
	split = ft_split(joined, '\n');
	if (split == NULL)
		return (ft_error_sl("Error\nWhile splitting (start_and_error)\n"));
	vars->map = split;
	ft_so_long_init(vars, i);
	free(joined);
	if (error_check(vars, i))
		return (2);
	return (0);
}
