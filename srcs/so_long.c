/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:44:21 by agallipo          #+#    #+#             */
/*   Updated: 2022/01/27 19:41:59 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_event(int key, void *mlx_ptr, void *mlx_win)
{
	printf("key = %d\n", key);
	if (key == 123)
	{

	}
}

int	main(int argc, char *argv[])
{
	t_map	map;
	s_pointers *mlx;

	mlx = ft_calloc(sizeof(s_pointers *), 1);
	map = ft_create_map(argv);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, (map.len - 1) * 32, (map.size/map.len) * 32, "Hello world!");
	ft_fill_map_with_images(map, mlx);
	mlx_key_hook(mlx->win, &key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
