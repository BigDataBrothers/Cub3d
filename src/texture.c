/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:21:21 by jskiba            #+#    #+#             */
/*   Updated: 2024/06/14 19:05:26 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_textures(t_vars *vars)
{
	vars->tex_north = mlx_xpm_file_to_image(vars->mlx, vars->map->no_texture, \
	&vars->tex_width, &vars->tex_height);
	vars->tex_south = mlx_xpm_file_to_image(vars->mlx, vars->map->so_texture,
			&vars->tex_width, &vars->tex_height);
	vars->tex_east = mlx_xpm_file_to_image(vars->mlx, vars->map->ea_texture, \
	&vars->tex_width, &vars->tex_height);
	vars->tex_west = mlx_xpm_file_to_image(vars->mlx, vars->map->we_texture, \
	&vars->tex_width, &vars->tex_height);
	if (!vars->tex_north || !vars->tex_south)
		error("Error loading textures", vars);
	if (!vars->tex_east || !vars->tex_west)
		error("Error loading textures", vars);
	vars->tex_data_north = mlx_get_data_addr(vars->tex_north, &vars->tex_bpp, \
	&vars->tex_size_line, &vars->tex_endian);
	vars->tex_data_south = mlx_get_data_addr(vars->tex_south, &vars->tex_bpp, \
	&vars->tex_size_line, &vars->tex_endian);
	vars->tex_data_east = mlx_get_data_addr(vars->tex_east, &vars->tex_bpp, \
	&vars->tex_size_line, &vars->tex_endian);
	vars->tex_data_west = mlx_get_data_addr(vars->tex_west, &vars->tex_bpp, \
	&vars->tex_size_line, &vars->tex_endian);
}
