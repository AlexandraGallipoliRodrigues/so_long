/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:39:26 by agallipo          #+#    #+#             */
/*   Updated: 2022/02/01 12:06:47 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_images
{
	void	*character;
	void	*background;
	void	*wall;
	void	*collect;
	void	*door;
	void	*enemy;
	int		width;
	int		height;
}			t_images;
typedef struct s_elem
{
	int	P;
	int	E;
	int	C;
}				t_elem;

typedef struct s_map
{
//	char	**map;
	int		size;
	int		len;
	int		height;
	char	*line;
	int		fd;
}				t_map;

typedef struct s_pointers
{
	void		*win;
	void		*ptr;
	char		**map_ref;
	int			player_y;
	int			player_x;
	int			enem_y;
	int			enem_x;
	int			cond;
	int			moves;
	t_map		map;
	t_elem		*elem;
	t_images	img;
}				t_pointers;

t_map	ft_create_map(char **argv, t_pointers *mlx);
void	ft_check_map(t_pointers *mlx);
int		ft_condition(t_pointers *mlx,  char  c);
void	ft_fill_map(t_pointers *mlx);
int		ft_map_size(char **argv);
void	ft_free_all(char **map, int i);
void	ft_printmap(char **map);
void	ft_fill_map_with_images(t_pointers *mlx);
void	ft_elements_images(t_pointers *mlx, t_images img, t_map map, int i, int j);
t_images	ft_init_images(void *mlx_ptr);
int	ft_enemy_moves(int cond, t_pointers *mlx);
void	ft_closewin(t_pointers *mlx);
#endif
