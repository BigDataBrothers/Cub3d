/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:44:27 by myassine          #+#    #+#             */
/*   Updated: 2024/05/31 23:50:13 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	skip_space(char *str, int i)
{
	while (str[i] && is_space(str[i]))
		i++;
	return (i);
}

int	is_wspace_line(char *str)
{
	int	i;

	i = 0;
	i = skip_space(str, i);
	if (str[i] && is_char(str[i]))
		return (0);
	return (1);
}

int	is_char(int c)
{
	if (c >= '!' && c <= '~')
		return (1);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, int len)
{
	int	i;

	i = 0;
	if (!s1 && s2)
		return (1);
	if (s1 && !s2)
		return (1);
	if (!s1 && !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
		len--;
		if (len == 0)
			return (0);
	}
	return (0);
}
