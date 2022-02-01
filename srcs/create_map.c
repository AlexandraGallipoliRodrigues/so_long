/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:38:24 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/01 16:23:46 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_valid_map(char **map, int num, int len)
{
	int	i;
	int	j;

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

int	ft_condition(t_pointers *mlx, char c)
{
	if (c == 'P')
		mlx->elem->player += 1;
	if (c == 'E')
		mlx->elem->exit += 1;
	if (c == 'C')
		mlx->elem->collect += 1;
	if (c != 'P' && c != 'E' && c != 'C'
		&& c != '1' && c != '0' && c != '\n')
		ft_closewin(mlx);
	return (0);
}

void	ft_check_map(t_pointers *mlx)
{
	int		i;
	int		j;
	int		num;

	mlx->elem = ft_calloc(sizeof(t_elem), 1);
	mlx->elem->player = 0;
	mlx->elem->exit = 0;
	mlx->elem->collect = 0;
	i = 0;
	num = mlx->map.size / mlx->map.len;
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
	if (mlx->elem->player != 1 || mlx->elem->exit != 1)
		ft_free_all(mlx->map_ref, mlx->map.size / mlx->map.len);
}

t_map	ft_create_map(char **argv, t_pointers *mlx)
{
	mlx->map.size = ft_map_size(argv);
	if (mlx->map.size == 0)
		exit(0);
	mlx->map.fd = open(argv[1], O_RDONLY);
	mlx->map.line = get_next_line(mlx->map.fd);
	mlx->map.len = ft_strlen(mlx->map.line);
	mlx->map_ref = ft_calloc(sizeof(char *), mlx->map.size / mlx->map.len + 1);
	ft_fill_map(mlx);
	ft_check_map(mlx);
	close(mlx->map.fd);
	return (mlx->map);
}
