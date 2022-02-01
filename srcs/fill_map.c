/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:01:25 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/01 16:06:06 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_map(t_pointers *mlx)
{
	int	i;

	i = 0;
	mlx->map_ref[i] = mlx->map.line;
	while (mlx->map_ref[i])
	{
		if (ft_strlen(mlx->map_ref[i]) != (size_t)mlx->map.len)
			ft_free_all(mlx->map_ref, i);
		else
		{
			i++;
			mlx->map_ref[i] = get_next_line(mlx->map.fd);
		}
	}
}

t_images	ft_init_images(void *mlx_ptr)
{
	t_images	img;

	img.wall = mlx_xpm_file_to_image(mlx_ptr, "sprites/WHOALL.xpm",
			&img.width, &img.height);
	img.character = mlx_xpm_file_to_image(mlx_ptr, "sprites/ANIM1F_1.xpm",
			&img.width, &img.height);
	img.background = mlx_xpm_file_to_image(mlx_ptr, "sprites/BRIK.xpm",
			&img.width, &img.height);
	img.collect = mlx_xpm_file_to_image(mlx_ptr, "sprites/collectionable.xpm",
			&img.width, &img.height);
	img.door = mlx_xpm_file_to_image(mlx_ptr, "sprites/puerta1.xpm", &img.width,
			&img.height);
	img.enemy = mlx_xpm_file_to_image(mlx_ptr, "sprites/ANIM1F_1.xpm",
			&img.width, &img.height);
	return (img);
}

void	ft_elements_images(t_pointers *mlx, t_images img, int i, int j)
{
	if (mlx->map_ref[i][j] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.wall, j * 32, i * 32);
	if (mlx->map_ref[i][j] == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			img.background, j * 32, i * 32);
	if (mlx->map_ref[i][j] == 'P')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			img.character, j * 32, i * 32);
		mlx->player_x = j;
		mlx->player_y = i;
	}
	if (mlx->map_ref[i][j] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			img.door, j * 32, i * 32);
	if (mlx->map_ref[i][j] == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			img.collect, j * 32, i * 32);
	if (mlx->map_ref[i][j] == 'N')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.enemy, j * 32, i * 32);
		mlx->enem_x = j;
		mlx->enem_y = i;
	}
}

void	ft_fill_map_with_images(t_pointers *mlx)
{
	int			i;
	int			j;
	t_images	img;

	img = ft_init_images(mlx->ptr);
	i = 0;
	while (i < (mlx->map.size / mlx->map.len))
	{
		j = 0;
		while (j < mlx->map.len)
		{
			ft_elements_images(mlx, img, i, j);
			j++;
		}
		i++;
	}
}
