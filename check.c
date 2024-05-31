/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:20:40 by myassine          #+#    #+#             */
/*   Updated: 2024/06/01 00:11:54 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_argc(int argc)
{
	if (argc < 2)
		return (err \
		("Error\nPlease provide a valid .cub map file as an argument.\n"), 1);
	else if (argc > 2)
		return (err \
		("Error\nToo many arguments provided. The program only accepts one \
.cub map file as an argument.\n"), 1);
	return (0);
}

int	check_map_name(char *name, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(name);
	j = ft_strlen(ext);
	while (j >= 0)
	{
		if (name[i] != ext[j])
			return (err("Error\nInvalid file type. Please provide a valid \
.cub map file as an argument.\n"), 1);
		i--;
		j--;
	}
	return (0);
}

int	check_char(char one_char)
{
	if (one_char == '0' || one_char == '1' || one_char == ' ' || \
	one_char == '\t' || one_char == 'N' || one_char == 'S' || one_char == 'E' \
	|| one_char == 'W')
		return (0);
	return (1);
}

int	check_map(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (check_char(data->map[x][y]))
				return (err("Error\n"), \
				err(\
				"The following character is not authorized [0,1,N,S,E,W] != " \
				), printf("[%c]\n", data->map[x][y]), 1);
			y++;
		}
		x++;
	}
	return (0);
}

int	check_player(t_data *data)
{
	int	x;
	int	y;
	int	p;

	x = 0;
	p = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'N' || data->map[x][y] == 'S' || \
			data->map[x][y] == 'E' || data->map[x][y] == 'W')
				p++;
			if (p > 1)
				return (err ("Error\nThere can only be one player\n"), 0);
			y++;
		}
		x++;
	}
	if (p == 0)
		return (err("Error\nOne player is required\n"), 0);
	return (1);
}
