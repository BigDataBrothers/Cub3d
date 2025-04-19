/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:18:56 by myassine          #+#    #+#             */
/*   Updated: 2024/06/14 19:37:06 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*remove_leading_spaces(char *str)
{
	char	*result;

	if (str == NULL)
		return (NULL);
	while (*str && is_space(*str))
		str++;
	result = ft_strdup(str);
	if (result == NULL)
		return (err("Error\nAllocation Fail\n"), NULL);
	return (result);
}

char	*remove_trailing_spaces(char *str)
{
	int		len;
	int		end_index;
	char	*result;

	len = ft_strlen(str);
	end_index = len - 1;
	if (str == NULL)
		return (NULL);
	while (end_index >= 0 && is_space(str[end_index]))
	{
		str[end_index] = '\0';
		end_index--;
	}
	result = (char *)malloc(end_index + 2);
	if (result == NULL)
		return (err("Error\nAllocation Fail\n"), NULL);
	ft_strcpy(result, (const char *)str);
	return (result);
}

int	game_loop(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	perform_raycasting(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_buffer, 0, 0);
	return (0);
}

int	close_window(t_vars *vars)
{
	free_textures(vars);
	free_images(vars);
	vars->map->map = free_tab(vars->map->map);
	free_data(vars);
	free(vars->map);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_memset(&vars, 0, sizeof(vars));
	if (check_argc(argc) || check_map_name(argv[1], ".cub"))
		return (0);
	vars.map = check_and_pars(argv, &vars);
	if (!vars.map)
		return (free_data_1(vars.map), 0);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		error("Error initializing MLX", &vars);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (vars.win == NULL)
		error("Error creating window", &vars);
	init_direction(&vars);
	load_textures(&vars);
	vars.img_buffer = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	vars.img_data_buffer = mlx_get_data_addr(vars.img_buffer, &vars.bpp, \
	&vars.size_line, &vars.endian);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 17, 0L, close_window, &vars);
	mlx_loop_hook(vars.mlx, game_loop, &vars);
	mlx_loop(vars.mlx);
	close_window(&vars);
	return (0);
}
