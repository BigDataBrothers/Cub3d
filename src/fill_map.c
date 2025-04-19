/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:43:03 by myassine          #+#    #+#             */
/*   Updated: 2024/06/14 16:04:32 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*fill_map_data2(int *rd, int fd, char *map, char *buff)
{
	char	*tmp;

	tmp = map;
	if (!tmp)
		return (NULL);
	while (*rd > 0)
	{
		tmp = ft_strjoin(tmp, buff);
		if (!tmp)
		{
			ft_free_elem((void **)&map);
			close(fd);
			return (NULL);
		}
		ft_bzero(buff, 2);
		*rd = read(fd, buff, 1);
	}
	if (*rd == -1)
	{
		free(tmp);
		close(fd);
		return (NULL);
	}
	return (close(fd), tmp);
}

char	*fill_map_data(char *file)
{
	int		fd;
	int		rd;
	char	*map;
	char	buff[2];
	char	*result;

	map = NULL;
	rd = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (err("Error\nOpening file as fail.\n"), NULL);
	map = malloc(sizeof(char) * 2);
	if (!map)
	{
		close(fd);
		return (err("Error\nOpening file as fail.\n"), NULL);
	}
	ft_bzero(map, 1);
	ft_bzero(buff, 2);
	result = fill_map_data2(&rd, fd, map, buff);
	if (!result || !*result)
		return (close(fd), free(result), err("Error\nReading file as fail.\n"), \
		NULL);
	return (result);
}
