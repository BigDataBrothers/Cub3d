/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:39:45 by myassine          #+#    #+#             */
/*   Updated: 2024/05/25 18:59:02 by myassine         ###   ########.fr       */
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

void	print_tab(char **tab)
{
	if (!tab)
		return;
	int	i;

	i = -1;
	while(tab[++i])
		printf("tab[%d] = %s\n", i, tab[i]);
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
        while (*p && is_space(*p))
            p++;
		if ((!ft_strncmp(p, "NO ", 3) || !ft_strncmp(p, "NO\t", 3)) && data->no_texture == NULL)
		{
			data->no_texture = ft_strdup(p + 3);
			if (!data->no_texture)
				return (0);  // prévoir les free
		}			
		else if ((!ft_strncmp(p, "SO ", 3) || !ft_strncmp(p, "SO\t", 3)) && data->so_texture == NULL)
		{
			data->so_texture = ft_strdup(p + 3);
			if (!data->so_texture)
				return (0);  // prévoir les free
		}
		else if ((!ft_strncmp(p, "WE ", 3) || !ft_strncmp(p, "WE\t", 3)) && data->we_texture == NULL)
		{
			data->we_texture = ft_strdup(p + 3);
			if (!data->we_texture)
				return (0);  // prévoir les free
		}
		else if ((!ft_strncmp(p, "EA ", 3) || !ft_strncmp(p, "EA\t", 3)) && data->ea_texture == NULL)
		{
			data->ea_texture = ft_strdup(p + 3);
			if (!data->ea_texture)
				return (0);  // prévoir les free	
		}
		else if (!ft_strncmp(p, "F ", 2) && (data->sol[0] == -1 && data->sol[1] == -1 && data->sol[2] == -1))
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
        }
        else if (!ft_strncmp(p, "C ", 2) && (data->plafond[0] == -1 && data->plafond[1] == -1 && data->plafond[2] == -1))
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
        }
		else if(data->no_texture != NULL && data->so_texture != NULL && data->ea_texture != NULL && data->we_texture != NULL &&
			data->sol[0] != -1 && data->sol[1] != -1 && data->sol[2] != -1 && data->plafond[0] != -1 &&
			data->plafond[1] != -1 && data->plafond[2] != -1)
				return (printf(BACK_PURPLE"iii"RST"\n"), ++x);
		else if(*p >= 33 && *p <= 126)
			return(printf(BACK_GREEN"iii"RST"\n") ,err("Error, Setting not good\n"), 0);
		x++;
	}
	if(data->no_texture != NULL && data->so_texture != NULL && data->ea_texture != NULL && data->we_texture != NULL &&
			data->sol[0] != -1 && data->sol[1] != -1 && data->sol[2] != -1 && data->plafond[0] != -1 &&
			data->plafond[1] != -1 && data->plafond[2] != -1)
				return (printf(BACK_YELLOW"iii"RST"\n"), ++x);
	printf(BACK_RED"iii"RST"\n");
	return(err("Error, Setting not good\n"), 0);
}

char	*set_back_n(char *str)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	while(str[++i])
	{
		if(str[i] == '\n' && str[i - 1] && str[i - 1] == '\n')
		{
			str[i] = '*';
			// while(str[i] && str[i] == '\n')
			// 	i++;
		}
	}
	// free(str);
	return (str);
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

int	check_char(char one_char)
{
	if(one_char == '0' || one_char == '1' || one_char == ' ' || one_char == '\t' \
		|| one_char == 'N' || one_char == 'S' || one_char == 'E' || one_char == 'W')
			return (0);
	return (1);			
}

int	check_map(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while(data->map[x])
	{
		y = 0;
		while(data->map[x][y])
		{
			if(check_char(data->map[x][y]))
				return(err("Error\n"), err("The following character is not authorized [0,1,N,S,E,W] != "), printf("[%c]\n", data->map[x][y]),1);
			y++;
		}
		x++;
	}
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
		return (free(map_s), free(data), 1);
	data->map = ft_split_m(map_s, '\n');
	if(!data->map)
		return (free(map_s), free(data), 1);
	print_tab(data->map);
	if(check_map(data))
		return (1);
	return (0);
}
