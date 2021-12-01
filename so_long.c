/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:44:21 by agallipo          #+#    #+#             */
/*   Updated: 2021/12/01 20:43:47 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main (int argc, char *argv[])
{
	//t_mlx	mlx;

	if (argc < 2)
		return (0);
	ft_create_map(argv);
	//ft_create_map(fd);
	//mlx.ptr = mlx_init();
}
