/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:44:21 by agallipo          #+#    #+#             */
/*   Updated: 2021/12/02 14:35:59 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main (int argc, char *argv[])
{
	t_mlx	mlx;
	t_data	msure;


	if (argc < 2)
		return (0);
	msure = ft_create_map(argv);
	mlx.ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.ptr, 900, 400, "map");
	mlx_hook();
	mlx_loop(mlx.ptr);
}
