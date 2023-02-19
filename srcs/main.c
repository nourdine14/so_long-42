/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:07 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/19 20:33:36 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_data(t_data *data)
{
	int	i;

	free(data->mlx);
	free(data->win);
	free(data->image);
	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
}

char	**get_height(char *map_name, t_data *data)
{
	char	**map;
	char	*line;
	int		fd;

	data->height = 0;
	fd = open(map_name, O_RDWR);
	if (fd < 0)
		return (ft_putstr_fd("no map entered", 2), NULL);
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

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;
	size_t	j;

	if (ac != 2)
		return (ft_putstr_fd("syntax error", 2), 1);
	data.c = 0;
	data.steps = 1;
	data.map = get_height(av[1], &data);
	fd = open(av[1], O_RDWR);
	j = -1;
	while (++j < data.height)
		data.map[j] = ft_strtrim(get_next_line(fd), "\n");
	if (!check_map(&data))
		return (ft_putstr_fd("BAD Map :(", 2), free_data(&data), 1);
	if (!check_flood_fill(&data))
		return (ft_putstr_fd("NO PATH VALID :(", 2), free_data(&data), 1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
			ft_strlen(data.map[0]) * SIZE, data.height * SIZE, "pipo");
	draw_map(&data);
	mlx_hook(data.win, 02, 0, &fun, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}
