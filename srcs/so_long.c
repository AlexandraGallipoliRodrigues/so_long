/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:44:21 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/01 11:37:39 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left_move(t_pointers *mlx)
{

	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == '1')
		return;
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'C')
		mlx->elem->C--;
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'E' && mlx->elem->C == 0)
		exit(0);
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'E' && mlx->elem->C != 0)
		return;
	mlx->player_x--;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y][mlx->player_x + 1] = '0';
	mlx->cond = ft_enemy_moves(mlx->cond, mlx);
	ft_fill_map_with_images(mlx);
	ft_printmap(mlx->map_ref);
}

void	ft_right_move(t_pointers *mlx)
{
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == '1')
		return;
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'C')
		mlx->elem->C--;
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'E' && mlx->elem->C == 0)
		exit(0);
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'E' && mlx->elem->C != 0)
		return;
	mlx->player_x++;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y][mlx->player_x - 1] = '0';
	mlx->cond = ft_enemy_moves(mlx->cond, mlx);
	ft_fill_map_with_images(mlx);
	ft_printmap(mlx->map_ref);
}
void	ft_up_move(t_pointers *mlx)
{
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == '1')
		return;
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'C')
		mlx->elem->C--;
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'E' && mlx->elem->C == 0)
		exit(0);
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'E' && mlx->elem->C != 0)
		return;
	mlx->player_y++;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y - 1][mlx->player_x] = '0';
	mlx->cond = ft_enemy_moves(mlx->cond, mlx);
	ft_fill_map_with_images(mlx);
	ft_printmap(mlx->map_ref);
}
void	ft_down_move(t_pointers *mlx)
{
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == '1')
		return;
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'C')
		mlx->elem->C--;
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'E' && mlx->elem->C == 0)
		exit(0);
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'E' && mlx->elem->C != 0)
		return;
	mlx->player_y--;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y + 1][mlx->player_x] = '0';
	mlx->cond = ft_enemy_moves(mlx->cond, mlx);
	ft_fill_map_with_images(mlx);
	ft_printmap(mlx->map_ref);
}
void	ft_key_event(int key, t_pointers *mlx)
{
	printf("key = %d\n", key);
	printf("moves = %d\n", mlx->moves);
	if (key == 123)
		ft_left_move(mlx);
	if (key == 124)
		ft_right_move(mlx);
	if (key == 125)
		ft_up_move(mlx);
	if (key == 126)
		ft_down_move(mlx);
	if (key == 53)
	{
		//ft_free_all(mlx->map_ref, mlx->map.len);
		exit(0);
	}
}
void	ft_closewin(t_pointers *mlx)
{
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_pointers *mlx;

	mlx = ft_calloc(sizeof(t_pointers), 1);
	mlx->map = ft_create_map(argv, mlx);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, (mlx->map.len - 1) * 32, (mlx->map.size/mlx->map.len) * 32, "Hello world!");
	ft_fill_map_with_images(mlx);
	mlx->moves = 0;
	mlx->cond = 1;
	mlx_hook(mlx->win, 17, 1L << 17, &ft_closewin, mlx);
	mlx_key_hook(mlx->win, &ft_key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
