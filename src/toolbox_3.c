/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:46:35 by myassine          #+#    #+#             */
/*   Updated: 2024/06/14 15:59:25 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_line_empty(char *s, char c)
{
	while (*s)
	{
		if (*s != c && *s != ' ' && *s != '\t' && *s != '\n')
			return (0);
		s++;
	}
	return (1);
}

int	ft_cntword_2(char *s, char c, int n)
{
	if (!s)
		return (-1);
	while (*s)
	{
		while (*s && (*s == c || *s == ' ' || *s == '\t'))
			s++;
		if (is_line_empty(s, c))
		{
			while (*s && *s != '\n')
				s++;
			if (*s == '\n')
				s++;
			continue ;
		}
		if (*s && *s != c && *s != ' ' && *s != '\t')
		{
			n++;
			while (*s && *s != c && *s != ' ' && *s != '\t')
				s++;
		}
		while (*s && (*s == c || *s == ' ' || *s == '\t'))
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
	printf(BLUE"i: %d"RESET"\n", i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	void	*ob;
	size_t	i;

	ob = b;
	i = 0;
	while (++i <= len)
		*(unsigned char *)b++ = (unsigned char)c;
	return ((void *)ob);
}
