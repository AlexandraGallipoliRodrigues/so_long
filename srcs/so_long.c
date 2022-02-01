/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:44:21 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/01 16:15:08 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	exit (0);
}

int	ft_key_event(int key, t_pointers *mlx)
{
	if (key == 123)
		ft_left_move(mlx);
	if (key == 124)
		ft_right_move(mlx);
	if (key == 125)
		ft_up_move(mlx);
	if (key == 126)
		ft_down_move(mlx);
	if (key == 53)
		ft_closewin(mlx);
	printf("moves = %d\n", mlx->moves);
	return (0);
}

int	ft_closewin(t_pointers *mlx)
{
	ft_free_all(mlx->map_ref, mlx->map.size / mlx->map.len);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_pointers	*mlx;

	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	mlx = ft_calloc(sizeof(t_pointers), 1);
	mlx->map = ft_create_map(argv, mlx);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, (mlx->map.len - 1) * 32,
			(mlx->map.size / mlx->map.len) * 32, "Hello world!");
	ft_fill_map_with_images(mlx);
	mlx->moves = 0;
	mlx->cond = 1;
	mlx_hook(mlx->win, 17, 1L << 17, ft_closewin, mlx);
	mlx_key_hook(mlx->win, ft_key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
