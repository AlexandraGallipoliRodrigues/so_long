/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:38:24 by agallipo          #+#    #+#             */
/*   Updated: 2022/01/27 18:14:32 by agallipo         ###   ########.fr       */
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

void	ft_fill_map(char **map, t_map *smth)
{
	int	i;

	i = 0;
	map[i]= smth->line;
	while (map[i])
	{
		if (ft_strlen(map[i]) != (size_t)smth->len)
			ft_free_all(map, i);
		else
		{
			i++;
			map[i]= get_next_line(smth->fd);
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
int	ft_condition(t_elem *ent,  char  c)
{
	if (c == 'P')
		ent->P += 1;
	if (c == 'E')
		ent->E += 1;
	if (c == 'E')
		ent->C += 1;
	return (0);
}

void	ft_check_map(char	**map, t_map *smth)
{
	t_elem	ent;
	int		i;
	int		j;
	int		num;

	ent.P = 0;
	ent.E = 0;
	ent.C = 0;
	i = 0;
	num = smth->size/smth->len;
	ft_valid_map(map, num, smth->len);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_condition(&ent, map[i][j]);
			j++;
		}
		i++;
	}
	if (ent.P != 1 || ent.E != 1)
		ft_free_all(map, smth->size/smth->len);
}

t_map	ft_create_map(char **argv)
{
	t_map	map;

	map.size = ft_map_size(argv);
	if (map.size == 0)
		exit(0);
	map.fd = open(argv[1],  O_RDONLY);
	map.line = get_next_line(map.fd);
	map.len = ft_strlen(map.line);
	map.map = ft_calloc(sizeof(char *), map.size/map.len + 1);
	ft_fill_map(map.map, &map);
	ft_check_map(map.map, &map);
	ft_printmap(map.map);
	close(map.fd);
	return (map);
}
t_images	ft_init_images(void *mlx_ptr)
{
	t_images	img;

	img.wall = mlx_xpm_file_to_image(mlx_ptr, "sprites/WHOALL.xpm", &img.width, &img.height);
	img.character = mlx_xpm_file_to_image(mlx_ptr, "sprites/ANIM1F_1.xpm", &img.width, &img.height);
	img.background = mlx_xpm_file_to_image(mlx_ptr, "sprites/BRIK.xpm", &img.width, &img.height);
	img.collect = mlx_xpm_file_to_image(mlx_ptr, "sprites/collectionable.xpm", &img.width, &img.height);
	img.door = mlx_xpm_file_to_image(mlx_ptr, "sprites/puerta1.xpm", &img.width, &img.height);
	return (img);
}

void	ft_elements_images(s_pointers *mlx, t_images img, t_map map, int i, int j)
{
	if (map.map[i][j] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.wall, j * 32, i * 32);
	if (map.map[i][j] == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.background, j * 32, i * 32);
	if (map.map[i][j] == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.character, j * 32, i * 32);
	if (map.map[i][j] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.door, j * 32, i * 32);
	if (map.map[i][j] == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.collect, j * 32, i * 32);

}
void	ft_fill_map_with_images(t_map map, s_pointers *mlx)
{
	int			i;
	int			j;
	t_images	img;

	img = ft_init_images(mlx->ptr);
	i = 0;
	while (i < (map.size/map.len))
	{
		j = 0;
		while (j < map.len)
		{
			ft_elements_images(mlx, img, map, i, j);
			j++;
		}
		i++;
	}
}
