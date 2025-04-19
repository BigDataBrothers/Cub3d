/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:00:36 by myassine          #+#    #+#             */
/*   Updated: 2024/06/14 16:08:41 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_split_3(char *s, char c, t_split *split, int j)
{
	int		i;
	int		max_len;
	char	**tmp1;

	tmp1 = split->tmp;
	max_len = max_substr_len(s, c);
	while (j--)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		*tmp1 = ft_substr_with_padding(s, 0, i, max_len);
		if (*tmp1 == NULL)
			return (ft_free(split->dst));
		tmp1++;
		while (*s && *s != c)
			s++;
	}
	*tmp1 = NULL;
}

void	ft_split_32(char *s, char c, t_split *split, int j)
{
	int		i;
	int		k;
	char	**tmp1;

	k = 0;
	tmp1 = split->tmp;
	while (j--)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		*tmp1 = ft_substr(s, 0, i);
		if (*tmp1 == NULL)
			return (ft_free(split->dst));
		tmp1++;
		k++;
		while (*s && *s != c)
			s++;
	}
	*tmp1 = NULL;
	return ;
}

char	**ft_split_m2(char *s, char c)
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
	ft_split_32(s, c, &split, j);
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
