/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:58:17 by myassine          #+#    #+#             */
/*   Updated: 2024/05/21 18:30:21 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	data_zero(t_data *a_data)
{
	a_data->map = NULL;
	a_data->plafond[0] = 0;
	a_data->plafond[1] = 0;
	a_data->plafond[2] = 0;
	a_data->sol[0] = 0;
	a_data->sol[1] = 0;
	a_data->sol[2] = 0;
	a_data->setting = NULL;
	a_data->ea_texture = NULL;
	a_data->no_texture = NULL;
	a_data->we_texture = NULL;
	a_data->so_texture = NULL;
}