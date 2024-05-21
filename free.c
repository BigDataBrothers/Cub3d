/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:02:04 by myassine          #+#    #+#             */
/*   Updated: 2024/05/20 19:02:26 by myassine         ###   ########.fr       */
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
