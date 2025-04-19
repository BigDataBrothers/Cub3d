/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:28:06 by jskiba            #+#    #+#             */
/*   Updated: 2024/06/12 19:37:53 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture_color(char *tex_data, int tex_x, int tex_y, t_vars *vars)
{
	char	*src;
	int		color;

	src = tex_data + (tex_y * vars->tex_size_line + tex_x * \
	(vars->tex_bpp / 8));
	color = *(unsigned int *)src;
	return (color);
}

void	put_texture_pixel(t_vars *vars, t_texture_pixel *pixel)
{
	int	color;

	color = get_texture_color(pixel->tex_data, pixel->tex_x, \
	pixel->tex_y, vars);
	put_pixel(vars, pixel->x, pixel->y, color);
}

void	draw_cell_floor(t_vars *vars, int ceiling_color, int floor_color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(vars, x, y, ceiling_color);
			x++;
		}
		y++;
	}
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(vars, x, y, floor_color);
			x++;
		}
		y++;
	}
}

void	select_texture(t_vars *vars, char **tex_data, double *wallX)
{
	if (vars->ray.side == 0)
	{
		*wallX = vars->ray.posy + vars->ray.perpwalldist * vars->ray.raydy;
		if (vars->ray.stepx > 0)
			*tex_data = vars->tex_data_south;
		else
			*tex_data = vars->tex_data_north;
	}
	else
	{
		*wallX = vars->ray.posx + vars->ray.perpwalldist * vars->ray.raydx;
		if (vars->ray.stepy > 0)
			*tex_data = vars->tex_data_east;
		else
			*tex_data = vars->tex_data_west;
	}
	*wallX -= floor(*wallX);
}

void	draw_texture(t_vars *vars, int x, char *tex_data, double wallX)
{
	t_texture_params	params;
	t_texture_pixel		pixel;

	params.tex_x = (int)(wallX * (double)(vars->tex_width));
	if (vars->ray.side == 0 && vars->ray.raydx > 0)
		params.tex_x = vars->tex_width - params.tex_x - 1;
	if (vars->ray.side == 1 && vars->ray.raydy < 0)
		params.tex_x = vars->tex_width - params.tex_x - 1;
	params.step = 1.0 * vars->tex_height / vars->ray.lineh;
	params.texpos = (vars->ray.dstart - WIN_HEIGHT / 2 + vars->ray.lineh / 2) \
	* params.step;
	pixel = (t_texture_pixel){x, vars->ray.dstart, params.tex_x, 0, tex_data};
	while (pixel.y < vars->ray.dend)
	{
		params.tex_y = (int)params.texpos & (vars->tex_height - 1);
		params.texpos += params.step;
		pixel.tex_y = params.tex_y;
		put_texture_pixel(vars, &pixel);
		pixel.y++;
	}
}
