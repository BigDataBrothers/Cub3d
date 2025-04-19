/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:12:08 by jskiba            #+#    #+#             */
/*   Updated: 2024/06/14 19:56:52 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_vars *vars)
{
	if (vars->map->map[(int)(vars->ray.posx + vars->ray.dirx * \
	MOVE_SPEED)][(int)(vars->ray.posy)] == '0')
		vars->ray.posx += vars->ray.dirx * MOVE_SPEED;
	if (vars->map->map[(int)(vars->ray.posx)][(int)(vars->ray.posy + \
	vars->ray.diry * MOVE_SPEED)] == '0')
		vars->ray.posy += vars->ray.diry * MOVE_SPEED;
}

void	move_backward(t_vars *vars)
{
	if (vars->map->map[(int)(vars->ray.posx - vars->ray.dirx * \
	MOVE_SPEED)][(int)(vars->ray.posy)] == '0')
		vars->ray.posx -= vars->ray.dirx * MOVE_SPEED;
	if (vars->map->map[(int)(vars->ray.posx)][(int)(vars->ray.posy - \
	vars->ray.diry * MOVE_SPEED)] == '0')
		vars->ray.posy -= vars->ray.diry * MOVE_SPEED;
}

void	move_left(t_vars *vars)
{
	if (vars->map->map[(int)(vars->ray.posx - vars->ray.planex * \
	MOVE_SPEED)][(int)(vars->ray.posy)] == '0')
		vars->ray.posx -= vars->ray.planex * MOVE_SPEED;
	if (vars->map->map[(int)(vars->ray.posx)][(int)(vars->ray.posy - \
	vars->ray.planey * MOVE_SPEED)] == '0')
		vars->ray.posy -= vars->ray.planey * MOVE_SPEED;
}

void	move_right(t_vars *vars)
{
	if (vars->map->map[(int)(vars->ray.posx + vars->ray.planex * \
	MOVE_SPEED)][(int)(vars->ray.posy)] == '0')
		vars->ray.posx += vars->ray.planex * MOVE_SPEED;
	if (vars->map->map[(int)(vars->ray.posx)][(int)(vars->ray.posy + \
	vars->ray.planey * MOVE_SPEED)] == '0')
		vars->ray.posy += vars->ray.planey * MOVE_SPEED;
}

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = vars->img_data_buffer + (y * vars->size_line + x * \
		(vars->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
