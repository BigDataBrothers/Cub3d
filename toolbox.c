/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:28:23 by myassine          #+#    #+#             */
/*   Updated: 2024/05/28 19:47:56 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int ft_tab_col_len(char **tab, int y) {
//     int x = 0;

//     if (tab == NULL) {
//         return 0;
//     }

//     while (tab[x]) {
//         printf("Vérification de tab[%d]: %s\n", x, tab[x]);
//         if (ft_strlen(tab[x]) < y) {
//             printf("Longueur de tab[%d] (%d) est inférieure à %d\n", x, ft_strlen(tab[x]), y);
//             break;
//         }
//         x++;
//     }
//     return x;
// }
int ft_tab_col_len(char **tab, int y)
{
    int x = 0;

    if (tab == NULL)
        return 0;
    while (tab[x])
	{
        if (ft_strlen(tab[x]) < y)
            break;
        x++;
    }
    return x;
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

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	skip_space(char *str, int i)
{
	while(str[i] && is_space(str[i]))
		i++;
	return (i);
}

int	is_wspace_line(char *str)
{
	int	i;

	i = 0;
	i = skip_space(str, i);
	if(str[i] && is_char(str[i]))
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
		if(len == 0)
			return (0);
	}
	return (0);
}

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
	// int	nul;
	int	i;
	int	nb;
	int	minus;

	// nul = 1;
	i = 0;
	nb = 0;
	minus = 1;
	i = skip_space(nptr, i);
	if (nptr[i] == '\0' || !ft_isdigit(nptr[i]))
		return (printf(BACK_RED"LLL"RST"\n") ,-1);
	while ((nptr[i]) && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if ((nptr[i] >= '0' && nptr[i] <= '9'))
		{
			nb = nb * 10 + (nptr[i] - '0');
			// nul = 0;
		}
		i++;
	}
	if(nptr[i] && is_space(nptr[i]))
	{
		i = skip_space(nptr, i);
		if((c == 'b'&& nptr[i]) || (c != 'b' && nptr[i] != ','))
			return (-1);
	}
	return (nb * minus);
}