/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:58:17 by myassine          #+#    #+#             */
/*   Updated: 2024/06/10 14:27:18 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	data_zero(t_data *a_data)
{
	a_data->map = NULL;
	a_data->plafond[0] = -1;
	a_data->plafond[1] = -1;
	a_data->plafond[2] = -1;
	a_data->sol[0] = -1;
	a_data->sol[1] = -1;
	a_data->sol[2] = -1;
	a_data->x = -1;
	a_data->y = -1;
	a_data->ea_texture = NULL;
	a_data->no_texture = NULL;
	a_data->we_texture = NULL;
	a_data->so_texture = NULL;
	a_data->pos = 0;
}

void	print_data(t_data *data)
{
	printf("data->so_texture: %s\n", data->so_texture);
	printf("data->we_texture: %s\n", data->we_texture);
	printf("data->no_texture: %s\n", data->no_texture);
	printf("data->ea_texture: %s\n", data->ea_texture);
	printf("data->sol[0]: %d\n", data->sol[0]);
	printf("data->sol[1]: %d\n", data->sol[1]);
	printf("data->sol[2]: %d\n", data->sol[2]);
	printf("data->plafond[0]: %d\n", data->plafond[0]);
	printf("data->plafond[1]: %d\n", data->plafond[1]);
	printf("data->plafond[2]: %d\n", data->plafond[2]);
}
