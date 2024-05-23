/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:00:36 by myassine          #+#    #+#             */
/*   Updated: 2024/05/23 20:00:16 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_cntword(char *s, char c, char c2, int n)
{
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			n++;
		while (*s && *s != c)
		{
			if(*s == c2)
				n++;
			s++;
		}
	}
	return (n);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i++])
		free (tab[i]);
	free (tab);
	return ;
}

void	ft_split_1(char *s, char c, t_split *split, int j)
{
	int		i;
	char	c2 = '*';
	char	**tmp1;

	tmp1 = split->tmp;
	while (j--)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && (s[i] != c && s[i] != c2))
			i++;
		if((s[i] == c2 && i != 0) || !s[i] || s[i] != c2)
			*tmp1 = ft_substr(s, 0, (i - 1));
		else
			*tmp1 = ft_strdup("");
		printf("*tmp1: %s j = %d i = %d\n", *tmp1, j, i);
		if (!tmp1++)
			ft_free(split->dst);
		while (*s && *s != c)
			s++;
	}
	return ;
}


char	**ft_split(char *s, char c)
{
	int			j;
	t_split		split;	

	if (!s)
		return (NULL);
	j = ft_cntword(s, c, '*', 0);
	split.tmp = malloc((j + 1) * sizeof(char *));
	if (!split.tmp)
		return (NULL);
	split.tmp[j] = 0;
	split.dst = split.tmp;
	ft_split_1(s, c, &split, j);
	return (split.dst);
}

//voir comment faire pour que quand char c est 2 fos d affiler il cree une ligne vide