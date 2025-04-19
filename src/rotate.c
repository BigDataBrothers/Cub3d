/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:19:26 by jskiba            #+#    #+#             */
/*   Updated: 2024/06/12 15:47:17 by jskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_left(t_vars *vars)
{
	double	olddirx;
	double	oldplanex;

	olddirx = vars->ray.dirx;
	vars->ray.dirx = vars->ray.dirx * cos(ROT_SPEED) - vars->ray.diry * \
	sin(ROT_SPEED);
	vars->ray.diry = olddirx * sin(ROT_SPEED) + vars->ray.diry * cos(ROT_SPEED);
	oldplanex = vars->ray.planex;
	vars->ray.planex = vars->ray.planex * cos(ROT_SPEED) - vars->ray.planey * \
	sin(ROT_SPEED);
	vars->ray.planey = oldplanex * sin(ROT_SPEED) + vars->ray.planey * \
	cos(ROT_SPEED);
}

void	rotate_right(t_vars *vars)
{
	double	olddirx;
	double	oldplanex;

	olddirx = vars->ray.dirx;
	vars->ray.dirx = vars->ray.dirx * cos(-ROT_SPEED) - vars->ray.diry * \
	sin(-ROT_SPEED);
	vars->ray.diry = olddirx * sin(-ROT_SPEED) + vars->ray.diry * \
	cos(-ROT_SPEED);
	oldplanex = vars->ray.planex;
	vars->ray.planex = vars->ray.planex * cos(-ROT_SPEED) - \
	vars->ray.planey * sin(-ROT_SPEED);
	vars->ray.planey = oldplanex * sin(-ROT_SPEED) + \
	vars->ray.planey * cos(-ROT_SPEED);
}

void	free_images(t_vars *vars)
{
	if (vars->img_buffer)
		mlx_destroy_image(vars->mlx, vars->img_buffer);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
}
