/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:38:24 by agallipo          #+#    #+#             */
/*   Updated: 2021/12/01 20:49:08 by agallipo         ###   ########.fr       */
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
	printf("HOLA");
	system("leaks so_long");
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

void	ft_fill_map(char **map, t_data *smth)
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

int	ft_condition(t_elem *ent,  char  c)
{
	if (c == 'P')
		ent->P += 1;
	if (c == 'E')
		ent->E += 1;
	if (c == 'E')
		ent->C += 1;
	if (ent->P > 1 || ent->E > 1)
		return (1);
	if (ent->P < 1 || ent->E < 1)
		return (1);
	return (0);
}
void	ft_check_map(char	**map, t_data *smth)
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
	while (num > 0)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_condition(&ent, map[i][j]) == 1)
				ft_free_all(map, smth->size/smth->len);
			j++;
		}
		i++;
		num--;
	}
}

void	ft_create_map(char **argv)
{
	char	**map;
	t_data	smth;

	smth.size = ft_map_size(argv);
	if (smth.size == 0)
		exit (0);
	smth.fd = open(argv[1],  O_RDONLY);
	smth.line = get_next_line(smth.fd);
	smth.len = ft_strlen(smth.line);
	map = ft_calloc(sizeof(char *) , smth.size/smth.len + 2);
	ft_fill_map(map, &smth);
	ft_check_map(map, &smth);
	ft_printmap(map);
	close(smth.fd);
}
