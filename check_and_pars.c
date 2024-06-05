/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:39:45 by myassine          #+#    #+#             */
/*   Updated: 2024/06/05 12:56:09 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	first_map_line(char *s, char c)
{
	int	i;
	int	res;

	i = 6;
	res = 0;
	while (*s)
	{
		while (*s && *s == c)
		{
			s++;
			res++;
		}
		while (*s && *s != c)
		{
			s++;
			res++;
		}
		i--;
		if (i == 0)
			break ;
	}
	return (res);
}

int	flood_fill(char **arr, int x, int y)
{
	if (x < 0 || x >= ft_tab_col_len(arr, y) || y < 0 || y >= ft_strlen(arr[x]))
		return (err("Error\nmap non entourer\n"), 1);
	if (arr[x][y] == '1' || arr[x][y] == '2' || arr[x][y] == '3')
		return (0);
	if (arr[x][y] != '0' && arr[x][y] != '1' && arr[x][y] != '2' && \
		arr[x][y] != '3')
	{
		printf("Error:\nCaractère invalide '%c' à la position (%d, %d)\n" \
			, arr[x][y], x, y);
		return (1);
	}
	if (arr[x][y] == '0')
		arr[x][y] = '2';
	if (flood_fill(arr, x + 1, y) == 1)
		return (1);
	if (flood_fill(arr, x - 1, y) == 1)
		return (1);
	if (flood_fill(arr, x, y + 1) == 1)
		return (1);
	if (flood_fill(arr, x, y - 1) == 1)
		return (1);
	return (0);
}

int	pos_player(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (data->map[++x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'N' || data->map[x][y] == 'S' \
			|| data->map[x][y] == 'E' || data->map[x][y] == 'W')
				break ;
			y++;
		}
		if (data->map[x][y] == 'N' || data->map[x][y] == 'S' \
			|| data->map[x][y] == 'E' || data->map[x][y] == 'W')
			break ;
	}
	data->map[x][y] = '3';
	if (flood_fill(data->map, x + 1, y) == 1 \
		|| flood_fill(data->map, x - 1, y) == 1 \
		|| flood_fill(data->map, x, y + 1) == 1 \
		|| flood_fill(data->map, x, y - 1) == 1)
		return (1);
	return (0);
}

int	check_and_pars_1(char *map_s, t_data *data, int x)
{
	int	tte;

	tte = first_map_line(map_s, '\n');
	map_s += tte;
	free_tab(data->map);
	if (x == 0)
		return (1);
	data->map = ft_split_m(map_s, '\n');
	if (!data->map)
		return (1);
	map_s -= tte;
	free(map_s);
	print_tab(data->map);
	if (check_map(data))
		return (1);
	if (!check_player(data))
		return (1);
	if (pos_player(data))
		return (1);
	print_tab(data->map);
	free_data(data);
}

int	check_and_pars(char **argv)
{
	int		x;
	char	*map_s;
	t_data	*data;

	x = 0;
	map_s = NULL;
	map_s = fill_map_data(argv[1]);
	if (!map_s)
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (free(map_s), 1);
	data_zero(data);
	data->map = ft_split(map_s, '\n');
	if (!data->map)
		return (free(map_s), free(data), 1);
	print_tab(data->map);
	x = set_setting(data);
	print_data(data);
	if (check_and_pars_1(map_s, data, x))
		return (1);
	return (0);
}
