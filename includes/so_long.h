/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:39:26 by agallipo          #+#    #+#             */
/*   Updated: 2022/01/27 19:09:45 by agallipo         ###   ########.fr       */
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
	int		width;
	int		height;
}			t_images;
typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	int		width;
	int		height;
	char	*name;

}				t_mlx;
typedef struct s_elem
{
	int	P;
	int	E;
	int	C;
}				t_elem;

typedef struct s_map
{
	char	**map;
	int		size;
	int		len;
	int		height;
	char	*line;
	int		fd;
}				t_map;

typedef struct t_pointers
{
	void	*win;
	void	*ptr;
	char	**map_ref;
}				s_pointers;

t_map	ft_create_map(char **argv);
void	ft_check_map(char	**map, t_map *smth);
int		ft_condition(t_elem *ent,  char  c);
void	ft_fill_map(char **map, t_map *smth);
int		ft_map_size(char **argv);
void	ft_free_all(char **map, int i);
void	ft_printmap(char **map);
void	ft_fill_map_with_images(t_map map, s_pointers *mlx);
void	ft_elements_images(s_pointers *mlx, t_images img, t_map map, int i, int j);
t_images	ft_init_images(void *mlx_ptr);
#endif
