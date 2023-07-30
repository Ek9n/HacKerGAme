/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:25:52 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/28 03:27:35 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	f_fill_helper(const char **tab, t_vars *vars, \
					const int row, const int col)
{
	if (tab[row][col] == 'P')
		vars->p_ctr--;
	else if (tab[row][col] == 'E')
		vars->e_ctr--;
	else if (tab[row][col] == 'C')
		vars->c_ctr--;
}

static void	f_fill(char **tab, t_vars *vars, char target, t_point begin)
{
	int	row;
	int	col;

	row = begin.x;
	col = begin.y;
	if (tab[row][col] == 'C')
	{
		vars->c_ctr--;
		tab[row][col] = '1';
		return ;
	}
	if ((row < 0 || col < 0 || row >= vars->size_y || col >= vars->size_x) || \
		(tab[row][col] == '1') || (vars->c_ctr == 0 && vars->e_ctr == 0))
		return ;
	f_fill_helper((const char **)tab, vars, row, col);
	tab[row][col] = '1';
	begin.x -= 1;
	f_fill(tab, vars, target, begin);
	begin.x += 2;
	f_fill(tab, vars, target, begin);
	begin.y -= 1;
	begin.x -= 1;
	f_fill(tab, vars, target, begin);
	begin.y += 2;
	f_fill(tab, vars, target, begin);
}

void	flood_fill(char **tab, t_vars *vars, t_point begin)
{
	f_fill(tab, vars, tab[begin.x][begin.y], begin);
}
