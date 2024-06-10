/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:00:36 by myassine          #+#    #+#             */
/*   Updated: 2024/06/10 12:59:26 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_split_1(char *s, char c, t_split *split, int j)
{
	int		i;
	int		t;
	char	**tmp1;

	t = 6;
	(void)j;
	tmp1 = split->tmp;
	while (t--)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		*tmp1 = ft_substr(s, 0, i);
		if (!tmp1++)
			ft_free(split->dst);
		while (*s && *s != c)
			s++;
	}
	*tmp1 = NULL;
	return ;
}

void	ft_split_3(char *s, char c, t_split *split, int j)
{
	int		i;
	char	**tmp1;

	tmp1 = split->tmp;
	while (j--)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		*tmp1 = ft_substr(s, 0, i);
		if (!tmp1++)
			ft_free(split->dst);
		while (*s && *s != c)
			s++;
	}
	*tmp1 = NULL;
	return ;
}

char	**ft_split(char *s, char c)
{
	int			j;
	t_split		split;	

	if (!s)
		return (NULL);
	j = 0;
	j = ft_cntword(s, c, 0);
	if (j == -1)
		return (NULL);
	split.tmp = malloc((j + 1) * sizeof(char *));
	if (!split.tmp)
		return (NULL);
	split.tmp[j] = 0;
	split.dst = split.tmp;
	ft_split_1(s, c, &split, j);
	return (split.dst);
}

char	**ft_split_m(char *s, char c)
{
	int			j;
	t_split		split;	

	if (!s)
		return (NULL);
	j = ft_cntword_2(s, c, 0);
	if (j == -1)
		return (NULL);
	split.tmp = malloc(sizeof(char *) * (j + 1));
	if (!split.tmp)
		return (NULL);
	split.tmp[j] = 0;
	split.dst = split.tmp;
	ft_split_3(s, c, &split, j);
	return (split.dst);
}
