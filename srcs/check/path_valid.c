/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:50 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/15 20:41:58 by nakebli          ###   ########.fr       */
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

char	**dup_2d_arr(char **map, int height)
{
	int		i;
	char	**mapp;
	
	mapp = malloc (sizeof(char *) * (height + 1));
	if (!mapp)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		mapp[i] = ft_strdup(map[i]);
	}
	return (mapp);
}

void	free_2d_arr(char **map)
{
	int i;
	
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
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
	map = dup_2d_arr(data->map, data->height);
	map = flood_fill(map, data->player_pos.x,
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
	if (e == 0 && c == 0)
	{
		free_2d_arr(map);
		return (1);
	}
	free_2d_arr(map);
	return (0);
}
