/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:28:23 by myassine          #+#    #+#             */
/*   Updated: 2024/06/14 15:59:51 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_tab_col_len(char **tab, int y)
{
	int	x;

	x = 0;
	if (tab == NULL)
		return (0);
	while (tab[x])
	{
		if (tab[x] == NULL || ft_strlen(tab[x]) < y)
			break ;
		x++;
	}
	return (x);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;
	int		len;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j;
	s3 = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!s3)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[i + j] = s2[j];
	while (i + j < len + 1)
		s3[i + j++] = '\0';
	free((char *)s1);
	return (s3);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			a;
	unsigned char	*s1;

	s1 = s;
	a = 0;
	while (a < n)
		s1[a++] = '\0';
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	ls;
	size_t	i;
	char	*ns;

	if (!s)
		return (NULL);
	ls = ft_strlen(s);
	if (start > ls)
	{
		ns = (char *)malloc(1);
		ns[0] = '\0';
		return (ns);
	}
	if ((start + len) > ls)
		ns = malloc(ls - start + 1);
	else
		ns = malloc(len + 1);
	if (!ns)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		ns[i++] = s[start++];
	ns[i] = '\0';
	return (ns);
}
