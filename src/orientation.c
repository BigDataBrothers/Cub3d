/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:51:12 by jskiba            #+#    #+#             */
/*   Updated: 2024/06/14 15:49:50 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_dir_north(t_vars *vars)
{
	vars->ray.dirx = -1;
	vars->ray.diry = 0;
	vars->ray.planex = 0;
	vars->ray.planey = 0.66;
}

void	set_dir_south(t_vars *vars)
{
	vars->ray.dirx = 1;
	vars->ray.diry = 0;
	vars->ray.planex = 0;
	vars->ray.planey = -0.66;
}

void	set_dir_east(t_vars *vars)
{
	vars->ray.dirx = 0;
	vars->ray.diry = 1;
	vars->ray.planex = 0.66;
	vars->ray.planey = 0;
}

void	set_dir_west(t_vars *vars)
{
	vars->ray.dirx = 0;
	vars->ray.diry = -1;
	vars->ray.planex = -0.66;
	vars->ray.planey = 0;
}

void	init_direction(t_vars *vars)
{
	vars->ray.posx = vars->map->x;
	vars->ray.posx += 0.5;
	vars->ray.posy = vars->map->y;
	vars->ray.posy += 0.5;
	vars->ray.p_dir = vars->map->pos;
	if (vars->ray.p_dir == 'N')
		set_dir_north(vars);
	else if (vars->ray.p_dir == 'S')
		set_dir_south(vars);
	else if (vars->ray.p_dir == 'E')
		set_dir_east(vars);
	else if (vars->ray.p_dir == 'W')
		set_dir_west(vars);
	else
		error("Invalid player orientation", vars);
}
