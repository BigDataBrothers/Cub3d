/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:43:03 by myassine          #+#    #+#             */
/*   Updated: 2024/05/26 19:30:09 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*fill_map_data2(int *rd, int fd, char *map, char *buff)
{
	char	*tmp;

	tmp = NULL;
	tmp = map;
	if(!tmp)
		return (NULL);
	while (*rd > 0)
	{
		tmp = ft_strjoin(tmp, buff);
		if (!tmp)
			return (NULL);
		ft_bzero(buff, 2);
		*rd = read(fd, buff, 1);
	}
	if (*rd == -1)
		return (free(tmp), err("Error\nReading file.\n"), NULL);
	return (tmp);
}

char	*fill_map_data(char *file)
{
	int		fd;
	int		rd;
	char	*map;
	char	buff[2];

	map = NULL;
	rd = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		err("Error\nOpening file.\n");
		return (NULL);
	}
	map = malloc(sizeof(char) * 2);
	if (!map)
		return (NULL);
	ft_bzero(map, 1);
	ft_bzero(buff, 2);
	return (fill_map_data2(&rd, fd, map, buff));
}
