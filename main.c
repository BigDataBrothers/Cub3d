/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myassine <myassine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:18:56 by myassine          #+#    #+#             */
/*   Updated: 2024/05/20 18:50:29 by myassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
    if(check_argc(argc) || check_map_name(argv[1], ".cub") || check_and_pars(argv))
        return (0);
    printf(BACK_GREEN"GOOD"RST"\n");
    return (1);
}
