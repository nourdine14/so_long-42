/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:50 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/12 21:15:14 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	**flood_fill(char **map, size_t x, size_t y, size_t height)
{
	if (x < ft_strlen(map[0]) && y < height && map[y][x] != '1' && map[y][x] != 'F')
	{
		map[y][x] = 'F';
		flood_fill(map, x + 1, y, height);
		flood_fill(map, x - 1, y, height);
		flood_fill(map, x, y + 1, height);
		flood_fill(map, x, y - 1, height);
		return (map);
	}
	return (NULL);
}

int	check_flood_fill(t_data *data)
{
	char	**map;
	int		e;
	int		c;
	int		i;
	int		j;

	e = 0;
	c = 0;
	map = flood_fill(data->map, data->player_pos.x,
			data->player_pos.y, data->height);
	if (!map)
		return (0);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
		}
	}
	printf("e:%d\nc:%d\n", e,c);
	if (e == 0 && c == 0)
		return (1);
	return (0);
}
