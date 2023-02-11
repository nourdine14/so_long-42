/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:07 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/11 18:28:18 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**get_height(char *map_name, t_data *data)
{
	char	**map;
	int		fd;

	data->height = 0;
	fd = open(map_name, O_RDWR);
	if (fd < 0)
		return (ft_putstr_fd("no map entered", 2), NULL);
	while (get_next_line(fd))
		data->height += 1;
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
	int		j;
	char	*map_name;

	if (ac == 2)
	{
		map_name = av[1];
		data.map = get_height(map_name, &data);
		fd = open(map_name, O_RDWR);
		j = 0;
		while (j < data.height)
		{
			data.map[j] = ft_strtrim(get_next_line(fd), "\n");
			j++;
		}
		if (!check_map(&data))
			return (ft_putstr_fd("BAD Map :(", 1), 1);
		if (!pathe_valid(data.map, data.height))
			return (ft_putstr_fd("NO OATH VALID :(", 1), 1);
	}
	else
		ft_putstr_fd("syntax error", 1);
	return (0);
}
