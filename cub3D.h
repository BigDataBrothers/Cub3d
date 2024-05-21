/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:17:44 by myassine          #+#    #+#             */
/*   Updated: 2024/05/21 19:17:53 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>

// color
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

// bold color
# define BOLD_BLACK "\033[1;30m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_PURPLE "\033[1;35m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;37m"

// background
# define BACK_BLACK "\033[0;40m"
# define BACK_RED "\033[0;41;30m"
# define BACK_GREEN "\033[0;42;30m"
# define BACK_YELLOW "\033[0;43;30m"
# define BACK_BLUE "\033[0;44;30m"
# define BACK_PURPLE "\033[0;45;30m"
# define BACK_CYAN "\033[0;46;30m"
# define BACK_WHITE "\033[0;47;30m"

# define BACK_BOLD_BLACK "\033[1;40m"
# define BACK_BOLD_RED "\033[1;41;30m"
# define BACK_BOLD_GREEN "\033[1;42;30m"
# define BACK_BOLD_YELLOW "\033[1;43;30m"
# define BACK_BOLD_BLUE "\033[1;44;30m"
# define BACK_BOLD_PURPLE "\033[1;45;30m"
# define BACK_BOLD_CYAN "\033[1;46;30m"
# define BACK_BOLD_WHITE "\033[1;47;30m"

// underline color
# define UNDER_BLACK "\033[4;30m"
# define UNDER_RED "\033[4;31m"
# define UNDER_GREEN "\033[4;32m"
# define UNDER_YELLOW "\033[4;33m"
# define UNDER_BLUE "\033[4;34m"
# define UNDER_PURPLE "\033[4;35m"
# define UNDER_CYAN "\033[4;36m"
# define UNDER_WHITE "\033[4;37m"

# define RESET "\033[0m"
# define RST "\033[0m"

typedef struct s_split
{
	char	**tmp;
	char	**dst;
}	t_split;

typedef struct s_data
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		sol[3];
	int		plafond[3];
	char	**map;
}	t_data;


//main
int		main(int argc, char **argv);
//check_and_pars
int		check_and_pars(char **argv);
//check
int		check_argc(int argc);
int		check_map_name(char *name, char *ext);
//error
int		err(char *str);
//toolbox
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		is_space(int c);
int		skip_space(char *str, int i);
int		is_char(int c);
int		ft_strncmp(char *s1, char *s2, int len);
char	*ft_strdup(char *s);
char	*ft_strchr(char *str, int wanted);
int		ft_atoi(char *nptr);

int		is_wspace_line(char *str);
//file_map
char	*fill_map_data(char *file);
char	*fill_map_data2(int *rd, int fd, char *map, char *buff);
//init_data
void	data_zero(t_data *a_data);
//split
int		ft_cntword(char *s, char c, int n);
char	**ft_split(char *s, char c);
void	ft_split_1(char *s, char c, t_split *split, int j);
//free
void	free_tab(char **tab);

#endif