/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:39:26 by agallipo          #+#    #+#             */
/*   Updated: 2021/12/02 13:02:28 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include "libft/libft.h"

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
typedef struct s_data
{
	int		size;
	int		len;
	char	*line;
	int		fd;
	int		i;
	int		j;
}				t_data;
t_data	ft_create_map(char **argv);
void	ft_check_map(char	**map, t_data *smth);
int		ft_condition(t_elem *ent,  char  c);
void	ft_fill_map(char **map, t_data *smth);
int		ft_map_size(char **argv);
void	ft_free_all(char **map, int i);
void	ft_printmap(char **map);
#endif
