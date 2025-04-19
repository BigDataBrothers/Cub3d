/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:21:16 by myassine          #+#    #+#             */
/*   Updated: 2024/06/12 17:55:33 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

void	error(char *message, t_vars *vars)
{
	printf("\033[1;31m%s\033[0m\n", message);
	close_window(vars);
}

void	remap(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
			if (data->map[x][y] == '2')
				data->map[x][y] = '0';
	}
}

void	a1(t_data *data, int x, int y)
{
	data->pos = data->map[x][y];
	data->map[x][y] = '2';
	data_xy(data, x, y);
}
