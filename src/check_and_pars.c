/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:39:45 by myassine          #+#    #+#             */
/*   Updated: 2024/06/14 16:08:30 by myassine         ###   ########.fr       */
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
		y = -1;
		while (data->map[x][++y])
		{
			if (data->map[x][y] == 'N' || data->map[x][y] == 'S' \
			|| data->map[x][y] == 'E' || data->map[x][y] == 'W')
				break ;
		}
		if (data->map[x][y] == 'N' || data->map[x][y] == 'S' \
			|| data->map[x][y] == 'E' || data->map[x][y] == 'W')
			break ;
	}
	a1(data, x, y);
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
	char *original_map_s = map_s; 

	tte = first_map_line(map_s, '\n');
	map_s += tte;
	if (x == 0)
		return (1);
	data->map = ft_split_m(map_s, '\n');
	if (!data->map)
		return (1);
	map_s -= tte;
	ft_free_elem((void **)&original_map_s);
	if (check_map(data))
		return (1);
	if (!check_player(data))
		return (1);
	if (pos_player(data))
		return (1);
	remap(data);
	return (0);
}

t_data	*check_and_pars(char **argv, t_vars *vars)
{
	int		x;
	char	*map_s;
	t_data	*data;

	x = 0;
	map_s = NULL;
	map_s = fill_map_data(argv[1]);
	if (!map_s || !*map_s)
		return (NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_free_elem((void **)&map_s), NULL);
	data_zero(data);
	data->map = ft_split_m2(map_s, '\n');
	if (!data->map)
		return (ft_free_elem((void **)&map_s), \
			ft_free_elem((void **)&data), NULL);
	x = set_setting(data);
	if (x == 0)
		return (ft_free_elem((void **)&map_s), NULL);
	data->map = free_tab(data->map);
	if (check_and_pars_1(map_s, data, x))
		return (free_data_1(data), NULL);
	(void)vars;
	return (data);
}
