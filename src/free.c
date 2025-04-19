/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:02:04 by myassine          #+#    #+#             */
/*   Updated: 2024/06/14 16:04:09 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		if (tab[i] != NULL)
		{
			while (tab[i])
			{
				free (tab[i]);
				tab[i] = NULL;
				i++;
			}
		}
		free (tab);
	}
	return (NULL);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i++])
		free (tab[i]);
	free (tab);
	return ;
}

void	free_data_1(t_data *data)
{
	if (data)
	{
		if (data->no_texture)
			ft_free_elem((void **)&data->no_texture);
		data->no_texture = NULL;
		if (data->so_texture)
			ft_free_elem((void **)&data->so_texture);
		data->so_texture = NULL;
		if (data->we_texture)
			ft_free_elem((void **)&data->we_texture);
		data->we_texture = NULL;
		if (data->ea_texture)
			ft_free_elem((void **)&data->ea_texture);
		data->map = free_tab(data->map);
		data->ea_texture = NULL;
		ft_free_elem((void **)&data);
	}
}

void	free_data(t_vars *data)
{
	if (data->map->no_texture)
		ft_free_elem((void **)&data->map->no_texture);
	data->map->no_texture = NULL;
	if (data->map->so_texture)
		ft_free_elem((void **)&data->map->so_texture);
	data->map->so_texture = NULL;
	if (data->map->we_texture)
		ft_free_elem((void **)&data->map->we_texture);
	data->map->we_texture = NULL;
	if (data->map->ea_texture)
		ft_free_elem((void **)&data->map->ea_texture);
	data->map->ea_texture = NULL;
}

void	free_textures(t_vars *vars)
{
	if (vars->tex_north)
		mlx_destroy_image(vars->mlx, vars->tex_north);
	if (vars->tex_south)
		mlx_destroy_image(vars->mlx, vars->tex_south);
	if (vars->tex_east)
		mlx_destroy_image(vars->mlx, vars->tex_east);
	if (vars->tex_west)
		mlx_destroy_image(vars->mlx, vars->tex_west);
}
