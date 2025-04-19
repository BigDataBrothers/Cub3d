/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:55:15 by myassine          #+#    #+#             */
/*   Updated: 2024/06/14 18:05:45 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	max_substr_len(char *s, char c)
{
	int	max_len;
	int	curr_len;

	max_len = 0;
	curr_len = 0;
	while (*s)
	{
		curr_len = 0;
		while (*s && *s == c)
			s++;
		while (s[curr_len] && s[curr_len] != c)
			curr_len++;
		if (curr_len > max_len)
			max_len = curr_len;
		while (*s && *s != c)
			s++;
	}
	return (max_len);
}

char	*ft_substr_with_padding(char *s, int start, int len, int max_len)
{
	char	*substr;
	int		i;

	substr = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	while (i < max_len)
	{
		substr[i] = ' ';
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	data_xy(t_data *data, int x, int y)
{
	data->x = x;
	data->y = y;
}

int	validate_data(t_data *data)
{
	if (data->no_texture && data->so_texture && data->we_texture && \
		data->ea_texture && data->sol[0] != -1 && data->sol[1] != -1 && \
		data->sol[2] != -1 && data->plafond[0] != -1 && \
		data->plafond[1] != -1 && data->plafond[2] != -1)
		return (1);
	return (0);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*p;

	p = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (p);
}
