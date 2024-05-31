/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:46:35 by myassine          #+#    #+#             */
/*   Updated: 2024/06/01 00:07:23 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_cntword_2(char *s, char c, int n)
{
	char	*cmp;

	while (*s && *s == c)
		s++;
	while (*s)
	{
		cmp = s;
		cmp++;
		if (*s && *s == c && *cmp && *cmp == c)
		{
			while (*cmp && (*cmp == c || is_space(*cmp)))
				cmp++;
			if (!*cmp)
				return (n);
			return (err("Error\nMap not good\n"), -1);
		}
		else if (*s && *s == c)
			s++;
		if (*s && *s != c)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

int	len_no_space(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	while (str[i])
	{
		if (is_space(str[i]))
		{
			res++;
			while (str[i] && is_space(str[i]))
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

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		printf("tab[%d] = %s\n", i, tab[i]);
}
