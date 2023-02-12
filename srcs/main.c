/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:07 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/12 21:18:52 by nakebli          ###   ########.fr       */
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
	size_t	j;
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
			return (ft_putstr_fd("BAD Map :(", 2), 1);
		if (!check_flood_fill(&data))
			return (ft_putstr_fd("NO OATH VALID :(", 2), 1);
	}
	else
		ft_putstr_fd("syntax error", 2);
	return (0);
}
