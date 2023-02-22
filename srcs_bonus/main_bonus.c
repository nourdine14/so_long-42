/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:07 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/21 12:52:56 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	befor_exit(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(1);
}

char	**get_height(char *map_name, t_data *data)
{
	char	**map;
	char	*line;
	int		fd;

	printf("%s", map_name);
	data->height = 0;
	fd = open(map_name, O_RDWR);
	if (fd < 0)
		befor_exit("\x1B[31mno map found");
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
	check_map(data);
	check_flood_fill(data);
	return (1);
}

int	destroy(t_data *data)
{
	if (data->image)
		mlx_destroy_image(data->mlx, data->image);
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac != 2 || ft_strlen(av[1]) < 4)
		befor_exit("\x1B[31msyntax error");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 5))
		befor_exit("\x1B[31mmap extension should be [.ber]");
	data.c = 0;
	data.steps = 1;
	data.map = get_height(av[1], &data);
	if (!data.map || data.height < 3)
		befor_exit("\x1B[31m ERROR : empty map or map file not found");
	fd = open(av[1], O_RDWR);
	if (!check_all(&data, fd))
		return (1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
			ft_strlen(data.map[0]) * SIZE, (data.height * SIZE) + 40, "pipo");
	draw_map(&data);
	mlx_hook(data.win, 02, 0, &fun, &data);
	mlx_hook(data.win, 17, 0, &destroy, &data);
	mlx_loop(data.mlx);
	return (0);
}
