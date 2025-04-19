/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:25:39 by jskiba            #+#    #+#             */
/*   Updated: 2024/06/10 16:26:06 by jskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	else if (keycode == 119)
		move_forward(vars);
	else if (keycode == 115)
		move_backward(vars);
	else if (keycode == 97)
		move_left(vars);
	else if (keycode == 100)
		move_right(vars);
	else if (keycode == 65361)
		rotate_left(vars);
	else if (keycode == 65363)
		rotate_right(vars);
	return (0);
}
