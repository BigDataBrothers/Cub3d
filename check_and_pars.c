/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:39:45 by myassine          #+#    #+#             */
/*   Updated: 2024/06/01 00:19:48 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_setting(t_data *data)
{
	int		x;
	char	*p;

	x = 0;
	p = NULL;
	while (data->map[x])
	{
		p = data->map[x];
		while (*p && is_space(*p))
			p++;
		if ((!ft_strncmp(p, "NO ", 3) || !ft_strncmp(p, "NO\t", 3)) && \
		data->no_texture == NULL)
		{
			data->no_texture = ft_strdup(p + 3);
			if (!data->no_texture)
				return (free_data (data), 0);
		}
		else if ((!ft_strncmp(p, "SO ", 3) || !ft_strncmp(p, "SO\t", 3)) && \
		data->so_texture == NULL)
		{
			data->so_texture = ft_strdup(p + 3);
			if (!data->so_texture)
				return (free_data (data), 0);
		}
		else if ((!ft_strncmp(p, "WE ", 3) || !ft_strncmp(p, "WE\t", 3)) && \
		data->we_texture == NULL)
		{
			data->we_texture = ft_strdup(p + 3);
			if (!data->we_texture)
				return (free_data (data), 0);
		}
		else if ((!ft_strncmp(p, "EA ", 3) || !ft_strncmp(p, "EA\t", 3)) && \
		data->ea_texture == NULL)
		{
			data->ea_texture = ft_strdup(p + 3);
			if (!data->ea_texture)
				return (free_data (data), 0);
		}
		else if (!ft_strncmp(p, "F ", 2) && (data->sol[0] == -1 && \
		data->sol[1] == -1 && data->sol[2] == -1))
		{
			char *q = p + 2;
			int r = ft_atoi(q, 'r');
			q = ft_strchr(q, ',') + 1;
			int g = ft_atoi(q, 'g');
			q = ft_strchr(q, ',') + 1;
			int b = ft_atoi(q, 'b');
			if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
				return (err("Error\nRGB values must be between 0 and 255\n"),1);
			data->sol[0] = r;
			data->sol[1] = g;
			data->sol[2] = b;
		}
		else if (!ft_strncmp(p, "C ", 2) && (data->plafond[0] == -1 && data->plafond[1] == -1 && data->plafond[2] == -1))
		{
			char *q = p + 2;
			int r = ft_atoi(q, 'r');
			q = ft_strchr(q, ',') + 1;
			int g = ft_atoi(q, 'g');
			q = ft_strchr(q, ',') + 1;
			int b = ft_atoi(q, 'b');
			if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
				return (err("Error\nRGB values must be between 0 and 255\n"),1);
			data->plafond[0] = r;
			data->plafond[1] = g;
			data->plafond[2] = b;
		}
		else if(data->no_texture != NULL && data->so_texture != NULL && data->ea_texture != NULL && data->we_texture != NULL &&
			data->sol[0] != -1 && data->sol[1] != -1 && data->sol[2] != -1 && data->plafond[0] != -1 &&
			data->plafond[1] != -1 && data->plafond[2] != -1)
				return (++x);
		else if(*p >= 33 && *p <= 126)
			return (err ("Error, Setting not good\n"), 0);
		x++;
	}
	if(data->no_texture != NULL && data->so_texture != NULL && data->ea_texture != NULL && data->we_texture != NULL &&
			data->sol[0] != -1 && data->sol[1] != -1 && data->sol[2] != -1 && data->plafond[0] != -1 &&
			data->plafond[1] != -1 && data->plafond[2] != -1)
				return (++x);
	return (err ("Error, Setting not good\n"), 0);
}


int	first_map_line(char *s, char c)
{
	int	i = 6;
	int	res = 0;

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
		if(i == 0)
			break;
	}
	return (res);
}

int	floodFill(char **arr, int x, int y)
{
    if (x < 0 || x >= ft_tab_col_len(arr, y) || y < 0 || y >= ft_strlen(arr[x]))
        return (err("Error\nmap non entourer\n"), 1);
    if (arr[x][y] == '1' || arr[x][y] == '2' || arr[x][y] == '3')
        return (0);
    if (arr[x][y] != '0' && arr[x][y] != '1' && arr[x][y] != '2' && arr[x][y] != '3')
	{
        printf("Error:\nCaractère invalide '%c' à la position (%d, %d)\n", arr[x][y], x, y);
        return (1);
    }
	if (arr[x][y] == '0')
        arr[x][y] = '2';
	if (floodFill(arr, x + 1, y) == 1)
		return (1);
    if (floodFill(arr, x - 1, y) == 1)
		return (1);
    if (floodFill(arr, x, y + 1) == 1)
		return (1);
    if (floodFill(arr, x, y - 1) == 1)
		return (1);
    return (0);
}

int	pos_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while(data->map[x])
	{
		y = 0;
		while(data->map[x][y])
		{
			if(data->map[x][y] == 'N' || data->map[x][y] == 'S'|| data->map[x][y] == 'E' || data->map[x][y] == 'W')
				break;
			y++;
		}
		if(data->map[x][y] == 'N' || data->map[x][y] == 'S'|| data->map[x][y] == 'E' || data->map[x][y] == 'W')
				break;
		x++;
	}
	data->map[x][y] = '3';
	if (floodFill(data->map, x + 1, y) == 1 || \
		floodFill(data->map, x - 1, y) == 1 || \
		floodFill(data->map, x, y + 1) == 1 || \
		floodFill(data->map, x, y - 1) == 1)
		return (1);
	return (0);
}


int check_and_pars(char **argv)
{
	int		x;
	char    *map_s;
	t_data  *data;

	x = 0;
	map_s = NULL;
	map_s = fill_map_data(argv[1]);
	if(!map_s)
		return (1);
	data = malloc(sizeof(t_data));
	if(!data)
		return(free(map_s), 1);
	data_zero(data);
	data->map = ft_split(map_s, '\n');
	if(!data->map)
		return (free(map_s), free(data), 1);
	print_tab(data->map);
	x = set_setting(data);
	print_data(data);
	int tte = first_map_line(map_s, '\n');
	map_s += tte;
	free_tab(data->map);
	if(x == 0)
		return (1);
	data->map = ft_split_m(map_s, '\n');
	if(!data->map)
		return (1);
	map_s -= tte;
	free(map_s);
	print_tab(data->map);
	if(check_map(data))
		return (1);
	if(!check_player(data))
		return (1);
	if(pos_player(data))
		return (1);
	print_tab(data->map);
	free_data(data);
	return (0);
}
