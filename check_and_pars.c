/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:39:45 by myassine          #+#    #+#             */
/*   Updated: 2024/05/22 19:41:03 by myassine         ###   ########.fr       */
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
		printf("x = %d 1 = %s\n", x, data->map[x]);
		
        while (*p && is_space(*p))
            p++;
		// printf("2 = %s\n", data->map[x]);
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
			printf("X value is : %d\n", x);	

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
				return (++x);
		else if(*p >= 33 && *p <= 126)
			return(err("Error, Setting not good\n"), 0);
		x++;
	}
	return (0);
}

//
char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	
	while (str[i])
	{
		if (str[i] && (str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (/str[i] != '\n'))
			i++;
	}
	
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	
	while (str[i])
	{
		if (str[i] && (/*str[i] == ' ' || str[i] == '\t' || */str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (/*str[i] != ' ' && str[i] != '\t' && */str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}
//

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
	data->map = ft_split(map_s);
	if(!data->map)
		return (free(map_s), free(data), 1);
	print_tab(data->map);
	x = set_setting(data);
	if(x == 0)
		return (free_tab(data->map) ,free(map_s), free(data), 1);
	printf(BLUE"x: %d"RESET"\n", x);
	return (0);
}
