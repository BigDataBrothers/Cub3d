/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:46:01 by myassine          #+#    #+#             */
/*   Updated: 2024/05/31 23:51:35 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strdup(char *s)
{
	int		len;
	int		i;
	char	*d;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(char *str, int character)
{
	int		i;
	char	*first_occurrence;

	i = 0;
	if (!str)
		return (NULL);
	first_occurrence = NULL;
	while (*str != '\0')
	{
		if (*str == character)
		{
			first_occurrence = str;
			while (first_occurrence[i])
				i++;
			first_occurrence[i] = '\0';
			break ;
		}
		str++;
	}
	return (first_occurrence);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *nptr, char c)
{
	int	i;
	int	nb;
	int	minus;

	i = 0;
	nb = 0;
	minus = 1;
	i = skip_space(nptr, i);
	if (nptr[i] == '\0' || !ft_isdigit(nptr[i]))
		return (-1);
	while ((nptr[i]) && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if ((nptr[i] >= '0' && nptr[i] <= '9'))
			nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] && is_space(nptr[i]))
	{
		i = skip_space(nptr, i);
		if ((c == 'b' && nptr[i]) || (c != 'b' && nptr[i] != ','))
			return (-1);
	}
	return (nb * minus);
}

int	ft_cntword(char *s, char c, int n)
{
	int	i;

	i = 6;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			n++;
		while (*s && *s != c)
			s++;
		i--;
	}
	return (n);
}
