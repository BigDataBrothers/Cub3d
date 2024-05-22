/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:00:36 by myassine          #+#    #+#             */
/*   Updated: 2024/05/22 19:51:40 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int ft_cntword(char *s, char c, int n)
// {
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (*s && *s != c)
// 			n++;
// 		while (*s && *s != c)
// 			s++;
// 	}
// 	return (n);
// }

// void	ft_split_1(char *s, char c, t_split *split, int j)
// {
// 	int		i;
// 	char	**tmp1;

// 	tmp1 = split->tmp;
// 	while (j--)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		i = 0;
// 		while (s[i] && s[i] != c)
// 			i++;
// 		*tmp1 = ft_substr(s, 0, i);
// 		if (!tmp1++)
// 			free_tab(split->dst);
// 		while (*s && *s != c)
// 			s++;
// 	}
// }

// char	**ft_split(char *s, char c)
// {
// 	int			j;
// 	t_split		split;	

// 	if (!s)
// 		return (NULL);
// 	j = ft_cntword(s, c, 0);
// 	split.tmp = malloc((j + 1) * sizeof(char *));
// 	if (!split.tmp)
// 		return (NULL);
// 	split.tmp[j] = 0;
// 	split.dst = split.tmp;
// 	ft_split_1(s, c, &split, j);
// 	return (split.dst);
// }
