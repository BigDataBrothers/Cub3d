/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pars_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:55:43 by myassine          #+#    #+#             */
/*   Updated: 2024/06/10 12:12:48 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_data(t_data *data)
{
	if (data->no_texture && data->so_texture && data->we_texture && \
		data->ea_texture && data->sol[0] != -1 && data->sol[1] != -1 && \
		data->sol[2] != -1 && data->plafond[0] != -1 && \
		data->plafond[1] != -1 && data->plafond[2] != -1)
		return (1);
	return (0);
}

int	set_texture(char *p, char **texture)
{
	*texture = ft_strdup(p + 3);
	if (!*texture)
		return (0);
	return (1);
}

int	set_color(char *p, int *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(p + 2, 'r');
	p = ft_strchr(p, ',') + 1;
	g = ft_atoi(p, 'g');
	p = ft_strchr(p, ',') + 1;
	b = ft_atoi(p, 'b');
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (err("Error\nRGB values must be between 0 and 255\n"), 0);
	color[0] = r;
	color[1] = g;
	color[2] = b;
	return (1);
}

int	parse_line(t_data *data, char *p)
{
	if ((!ft_strncmp(p, "NO ", 3) || !ft_strncmp(p, "NO\t", 3)) && \
		!data->no_texture)
		return (set_texture(p, &data->no_texture), 1);
	if ((!ft_strncmp(p, "SO ", 3) || !ft_strncmp(p, "SO\t", 3)) && \
		!data->so_texture)
		return (set_texture(p, &data->so_texture), 1);
	if ((!ft_strncmp(p, "WE ", 3) || !ft_strncmp(p, "WE\t", 3)) && \
		!data->we_texture)
		return (set_texture(p, &data->we_texture), 1);
	if ((!ft_strncmp(p, "EA ", 3) || !ft_strncmp(p, "EA\t", 3)) && \
		!data->ea_texture)
		return (set_texture(p, &data->ea_texture), 1);
	if (!ft_strncmp(p, "F ", 2) && (data->sol[0] == -1 && data->sol[1] == -1 && \
		data->sol[2] == -1))
		return (set_color(p, data->sol), 1);
	if (!ft_strncmp(p, "C ", 2) && (data->plafond[0] == -1 && \
		data->plafond[1] == -1 && data->plafond[2] == -1))
		return (set_color(p, data->plafond), 1);
	if (*p >= 33 && *p <= 126)
		return (err("Error, Setting not good\n"), 0);
	return (1);
}

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
		if (!parse_line(data, p))
			return (free_data (data), 0);
		if (validate_data(data))
			return (++x);
		x++;
	}
	if (validate_data(data))
		return (++x);
	return (free_data (data), err("Error, Setting not good\n"), 0);
}
