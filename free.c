/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:02:04 by myassine          #+#    #+#             */
/*   Updated: 2024/06/01 00:07:32 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab[i] != NULL)
	{
		while (tab[i])
		{
			free (tab[i]);
			tab[i] = NULL;
			i++;
		}
	}
	if (tab != NULL)
		free (tab);
	tab = NULL;
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

void	free_data(t_data *data)
{
	if (data->map)
		free_tab (data->map);
	if (data->no_texture)
		free (data->no_texture);
	if (data->so_texture)
		free (data->so_texture);
	if (data->we_texture)
		free (data->we_texture);
	if (data->ea_texture)
		free (data->ea_texture);
	free (data);
}
