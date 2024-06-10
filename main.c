/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:18:56 by myassine          #+#    #+#             */
/*   Updated: 2024/06/10 16:04:00 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data *data;

	if (check_argc(argc) || check_map_name(argv[1], ".cub"))
		return (0);
	data = check_and_pars(argv);
	if(!data)
		return (0);
	printf(BACK_GREEN"GOOD"RST"\n");
	free_tab(data->map);
	free_data(data);
	free(data);
	return (1);
}
