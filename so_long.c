/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:44:21 by agallipo          #+#    #+#             */
/*   Updated: 2022/01/26 12:40:08 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	main (int argc, char *argv[])
{
	t_mlx	mlx;
	t_data	msure;
	void	*img; //puntero de la imagen, con el buffer ya cargado


	if (argc < 2)
		return (0);
	msure = ft_create_map(argv);
	mlx.ptr = mlx_init();
	img = mlx_new_image(mlx.ptr, 1920, 1080);
	//add_shade(200, 0x0000FF00);
	mlx.window = mlx_new_window(mlx.ptr, 1920, 1080, "map");
	//mlx_hook();
	mlx_loop(mlx.ptr);
}*/

typedef	struct so_long
{
	void	*mlx_ptr;
	void	*mlx_win;

}	t_so_long;

void	key_event(int key, t_so_long *p)
{
	printf("key = %d\n", key);
	if (key == 51)
	{
		mlx_clear_window(p->mlx_ptr, p->mlx_win);

	}
	if (key == 36)
	{
		printf("HOLI\n");
		mlx_destroy_window(p->mlx_ptr, p->mlx_win);
		exit (0);
	}
	return ;
}


int	main(void)
{
	t_so_long	*p;
	void	*mlx_win;
	void	*mlx_ptr;

	p = ft_calloc(sizeof(t_so_long), sizeof(t_so_long));
	p->mlx_ptr = mlx_init();
	p->mlx_win = mlx_new_window(p->mlx_ptr, 1920, 1080, "Hello world!");
	printf("HOLI\n");
	mlx_string_put(p->mlx_ptr, p->mlx_win, 100, 500, 0xffffff, "HELLO 42\n");
	mlx_key_hook(p->mlx_win, &key_event, p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
