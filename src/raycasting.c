/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:28:46 by jskiba            #+#    #+#             */
/*   Updated: 2024/06/10 18:47:16 by jskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_ray_direction(t_vars *vars, int x)
{
	vars->ray.camx = 2 * x / (double)WIN_WIDTH - 1;
	vars->ray.raydx = vars->ray.dirx + vars->ray.planex * vars->ray.camx;
	vars->ray.raydy = vars->ray.diry + vars->ray.planey * vars->ray.camx;
}

void	calculate_step_and_initial_side_dist(t_vars *vars)
{
	if (vars->ray.raydx < 0)
	{
		vars->ray.stepx = -1;
		vars->ray.sidedx = (vars->ray.posx - vars->ray.mapx) * \
		vars->ray.deltadx;
	}
	else
	{
		vars->ray.stepx = 1;
		vars->ray.sidedx = (vars->ray.mapx + 1.0 - vars->ray.posx) * \
		vars->ray.deltadx;
	}
	if (vars->ray.raydy < 0)
	{
		vars->ray.stepy = -1;
		vars->ray.sidedy = (vars->ray.posy - vars->ray.mapy) * \
		vars->ray.deltady;
	}
	else
	{
		vars->ray.stepy = 1;
		vars->ray.sidedy = (vars->ray.mapy + 1.0 - vars->ray.posy) * \
		vars->ray.deltady;
	}
}

void	perform_dda(t_vars *vars)
{
	while (vars->ray.hit == 0)
	{
		if (vars->ray.sidedx < vars->ray.sidedy)
		{
			vars->ray.sidedx += vars->ray.deltadx;
			vars->ray.mapx += vars->ray.stepx;
			vars->ray.side = 0;
		}
		else
		{
			vars->ray.sidedy += vars->ray.deltady;
			vars->ray.mapy += vars->ray.stepy;
			vars->ray.side = 1;
		}
		if (vars->map->map[vars->ray.mapx][vars->ray.mapy] != '0')
			vars->ray.hit = 1;
	}
}

void	calculate_perp_wall_dist(t_vars *vars)
{
	if (vars->ray.side == 0)
		vars->ray.perpwalldist = (vars->ray.mapx - vars->ray.posx + \
		(1 - vars->ray.stepx) / 2) / vars->ray.raydx;
	else
		vars->ray.perpwalldist = (vars->ray.mapy - vars->ray.posy + \
		(1 - vars->ray.stepy) / 2) / vars->ray.raydy;
}

void	calculate_line_height_and_draw_positions(t_vars *vars)
{
	vars->ray.lineh = (int)(WIN_HEIGHT / vars->ray.perpwalldist);
	vars->ray.dstart = -vars->ray.lineh / 2 + WIN_HEIGHT / 2;
	if (vars->ray.dstart < 0)
		vars->ray.dstart = 0;
	vars->ray.dend = vars->ray.lineh / 2 + WIN_HEIGHT / 2;
	if (vars->ray.dend >= WIN_HEIGHT)
		vars->ray.dend = WIN_HEIGHT - 1;
}
