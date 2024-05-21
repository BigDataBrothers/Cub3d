/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:39:45 by myassine          #+#    #+#             */
/*   Updated: 2024/05/21 19:08:50 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int len_no_space(char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while(str[i] && is_space(str[i]))
		i++;
	while(str[i])
	{
		if(is_space(str[i]))
		{
			res++;
			while(str[i] && is_space(str[i]))
				i++;
		}
		res++;
		i++;
	}
	return (res);
}

int set_setting(t_data *data)
{
	int 	x;
	char	*p;

	x = 0;
	p = NULL;
	while(data->map[x])
	{
		p = data->map[x];
        while (*p && *p == ' ')
            p++;
		if (!ft_strncmp(p, "NO ", 3) || !ft_strncmp(p, "NO\t", 3))
		{
			data->no_texture = ft_strdup(p + 3);
			if (!data->no_texture)
				return (1);  // prévoir les free
			x++;
			continue;
		}			
		if (!ft_strncmp(p, "SO ", 3) || !ft_strncmp(p, "SO\t", 3))
		{
			data->so_texture = ft_strdup(p + 3);
			if (!data->so_texture)
				return (1);  // prévoir les free
			x++;
			continue;
		}
		if (!ft_strncmp(p, "WE ", 3) || !ft_strncmp(p, "WE\t", 3))
		{
			data->we_texture = ft_strdup(p + 3);
			if (!data->we_texture)
				return (1);  // prévoir les free
			x++;
			continue;
		}
		if (!ft_strncmp(p, "EA ", 3) || !ft_strncmp(p, "EA\t", 3))
		{
			data->ea_texture = ft_strdup(p + 3);
			if (!data->ea_texture)
				return (1);  // prévoir les free	
			x++;
			continue;
		}
		if (!ft_strncmp(p, "F ", 2))
        {
            char *q = p + 2;
            int r = ft_atoi(q);
            q = ft_strchr(q, ',') + 1;
            int g = ft_atoi(q);
            q = ft_strchr(q, ',') + 1;
            int b = ft_atoi(q);
            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
                return (err("Error\nRGB values must be between 0 and 255\n"),1);
            data->sol[0] = r;
			data->sol[1] = g;
			data->sol[2] = b;
            x++;
            continue;
        }
        if (!ft_strncmp(p, "C ", 2))
        {
            char *q = p + 2;
            int r = ft_atoi(q);
            q = ft_strchr(q, ',') + 1;
            int g = ft_atoi(q);
            q = ft_strchr(q, ',') + 1;
            int b = ft_atoi(q);
            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
				return (err("Error\nRGB values must be between 0 and 255\n"),1);
            data->plafond[0] = r;
			data->plafond[1] = g;
			data->plafond[2] = b;
            x++;
            continue;
        }
		x++;
	}
	return (0);
}

int check_and_pars(char **argv)
{
	char    *map_s;
	t_data  *data;

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
	if(set_setting(data))
		return (free_tab(data->map) ,free(map_s), free(data), 1);
	return (0);
}
