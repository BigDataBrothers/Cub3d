/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:44:04 by jskiba            #+#    #+#             */
/*   Updated: 2024/06/10 19:17:38 by jskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	rgb_to_hex(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	perform_raycasting(t_vars *vars)
{
	int		x;
	double	wallx;
	char	*tex_data;

	x = 0;
	vars->ceiling_color = rgb_to_hex(vars->map->plafond);
	vars->floor_color = rgb_to_hex(vars->map->sol);
	draw_cell_floor(vars, vars->ceiling_color, vars->floor_color);
	while (x < WIN_WIDTH)
	{
		calculate_ray_direction(vars, x);
		vars->ray.mapx = (int)vars->ray.posx;
		vars->ray.mapy = (int)vars->ray.posy;
		vars->ray.deltadx = fabs(1 / vars->ray.raydx);
		vars->ray.deltady = fabs(1 / vars->ray.raydy);
		vars->ray.hit = 0;
		calculate_step_and_initial_side_dist(vars);
		perform_dda(vars);
		calculate_perp_wall_dist(vars);
		calculate_line_height_and_draw_positions(vars);
		select_texture(vars, &tex_data, &wallx);
		draw_texture(vars, x, tex_data, wallx);
		x++;
	}
}
