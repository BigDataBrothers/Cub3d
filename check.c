/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:20:40 by myassine          #+#    #+#             */
/*   Updated: 2024/05/20 18:33:12 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_argc(int argc)
{
	if(argc < 2)
		return(err("Error\nPlease provide a valid .cub map file as an argument.\n"), 1);
	else if(argc > 2)
		return(err("Error\nToo many arguments provided. The program only accepts one .cub map file as an argument.\n"),1);
	return (0);
}

int	check_map_name(char *name, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(name);
	j = ft_strlen(ext);
	while (j >= 0)
	{
		if (name[i] != ext[j])
			return (err("Error\nInvalid file type. Please provide a valid .cub map file as an argument.\n"), 1);
		i--;
		j--;
	}
	return (0);
}