/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:07 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/20 10:14:47 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	befor_exit(char **map, char *msg)
{
	if (map)
		free_2d_arr(map);
	ft_putendl_fd(msg, 1);
	exit(1);
}

char	**get_height(char *map_name, t_data *data)
{
	char	**map;
	char	*line;
	int		fd;

	data->height = 0;
	fd = open(map_name, O_RDWR);
	if (fd < 0)
		return (befor_exit(NULL, "\x1B[31mno map found"), NULL);
	while (1)
	{
		line = get_next_line(fd);
		free (line);
		if (!line)
			break ;
		data->height += 1;
	}
	map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!map)
		return (NULL);
	close(fd);
	return (map);
}

int	check_all(t_data *data, int fd)
{
	size_t	j;

	j = -1;
	while (++j < data->height)
		data->map[j] = ft_strtrim(get_next_line(fd), "\n");
	if (!check_map(data))
		return (befor_exit(data->map, "\x1B[31mBAD Map :("), 0);
	if (!check_flood_fill(data))
		return (befor_exit(data->map, "\x1B[31mNO PATH VALID :("), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac != 2 || ft_strlen(av[1]) < 5)
		return (befor_exit(NULL, "\x1B[31msyntax error"), 1);
	if (!ft_strncmp(av[1] + ft_strlen(av[1]) - 5, ".ber", 5))
		return (befor_exit(NULL, "\x1B[31mmap should end with .ber"), 1);
	data.c = 0;
	data.steps = 1;
	data.map = get_height(av[1], &data);
	if (!data.map)
		return (1);
	fd = open(av[1], O_RDWR);
	if (!check_all(&data, fd))
		return (1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
			ft_strlen(data.map[0]) * SIZE, data.height * SIZE, "pipo");
	draw_map(&data);
	mlx_hook(data.win, 02, 0, &fun, &data);
	mlx_loop(data.mlx);
	return (0);
}
