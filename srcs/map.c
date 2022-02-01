/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:38:24 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/01 11:42:37 by agallipo         ###   ########.fr       */
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
	printf("ERROR\n");
	//system("leaks so_long");
	exit (0);
}

int	ft_map_size(char **argv)
{
	char	*buff;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	buff = malloc(sizeof(char));
	i = 0;
	while (read(fd, buff, 1))
		i++;
	free(buff);
	close(fd);
	return (i);
}

void	ft_fill_map(t_pointers *mlx)
{
	int	i;

	i = 0;
	mlx->map_ref[i]= mlx->map.line;
	while (mlx->map_ref[i])
	{
		if (ft_strlen(mlx->map_ref[i]) != (size_t)mlx->map.len)
			ft_free_all(mlx->map_ref, i);
		else
		{
			i++;
			mlx->map_ref[i]= get_next_line(mlx->map.fd);
		}
	}
}

void	ft_printmap(char **map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		printf("%s", map[i]);
		i++;
	}
}

void	ft_valid_map(char **map, int num, int len)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j < len - 1)
			{
				if (map[0][j] != '1' || map[num - 1][j] != '1'
				|| map[i][0] != '1' || map[i][len - 2] != '1')
					ft_free_all(map, num);
			}
			j++;
		}
		i++;
	}
}
int	ft_condition(t_pointers *mlx,  char  c)
{
	if (c == 'P')
		mlx->elem->P += 1;
	if (c == 'E')
		mlx->elem->E += 1;
	if (c == 'C')
		mlx->elem->C += 1;
	printf("C = %d\n", mlx->elem->C);
	return (0);
}

void	ft_check_map(t_pointers *mlx)
{
	int		i;
	int		j;
	int		num;

	mlx->elem = ft_calloc(sizeof(t_elem), 1);
	mlx->elem->P = 0;
	mlx->elem->E = 0;
	mlx->elem->C = 0;
	i = 0;
	num = mlx->map.size/mlx->map.len;
	ft_valid_map(mlx->map_ref, num, mlx->map.len);
	while (mlx->map_ref[i])
	{
		j = 0;
		while (mlx->map_ref[i][j])
		{
			ft_condition(mlx, mlx->map_ref[i][j]);
			j++;
		}
		i++;
	}
	if (mlx->elem->P != 1 || mlx->elem->E != 1)
		ft_free_all(mlx->map_ref, mlx->map.size/mlx->map.len);
}

t_map	ft_create_map(char **argv, t_pointers *mlx)
{
	mlx->map.size = ft_map_size(argv);
	if (mlx->map.size == 0)
		exit(0);
	mlx->map.fd = open(argv[1],  O_RDONLY);
	mlx->map.line = get_next_line(mlx->map.fd);
	mlx->map.len = ft_strlen(mlx->map.line);
	mlx->map_ref = ft_calloc(sizeof(char *), mlx->map.size/mlx->map.len + 1);
	ft_fill_map(mlx);
	ft_check_map(mlx);
	ft_printmap(mlx->map_ref);
	close(mlx->map.fd);
	return (mlx->map);
}
t_images	ft_init_images(void *mlx_ptr)
{
	t_images	img;

	img.wall = mlx_xpm_file_to_image(mlx_ptr, "sprites/WHOALL.xpm", &img.width, &img.height);
	img.character = mlx_xpm_file_to_image(mlx_ptr, "sprites/ANIM1F_1.xpm", &img.width, &img.height);
	img.background = mlx_xpm_file_to_image(mlx_ptr, "sprites/BRIK.xpm", &img.width, &img.height);
	img.collect = mlx_xpm_file_to_image(mlx_ptr, "sprites/collectionable.xpm", &img.width, &img.height);
	img.door = mlx_xpm_file_to_image(mlx_ptr, "sprites/puerta1.xpm", &img.width, &img.height);
	img.enemy = mlx_xpm_file_to_image(mlx_ptr, "sprites/ANIM1F_1.xpm", &img.width, &img.height);
	return (img);
}

void	ft_elements_images(t_pointers *mlx, t_images img, t_map map, int i, int j)
{
	if (mlx->map_ref[i][j] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.wall, j * 32, i * 32);
	if (mlx->map_ref[i][j] == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.background, j * 32, i * 32);
	if (mlx->map_ref[i][j] == 'P')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.character, j * 32, i * 32);
		mlx->player_x = j;
		mlx->player_y = i;
	}
	if (mlx->map_ref[i][j] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.door, j * 32, i * 32);
	if (mlx->map_ref[i][j] == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.collect, j * 32, i * 32);
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
	while (i < (mlx->map.size/mlx->map.len))
	{
		j = 0;
		while (j < mlx->map.len)
		{
			ft_elements_images(mlx, img, mlx->map, i, j);
			j++;
		}
		i++;
	}
}
