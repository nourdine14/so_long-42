/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:50 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/20 09:19:28 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	flood_fill(char **map, size_t x, size_t y, size_t height)
{
	if (x < ft_strlen(map[0]) && y < height
		&& map[y][x] != '1' && map[y][x] != 'X')
	{
		map[y][x] = 'X';
		flood_fill(map, x + 1, y, height);
		flood_fill(map, x - 1, y, height);
		flood_fill(map, x, y + 1, height);
		flood_fill(map, x, y - 1, height);
	}
}

char	**dup_2d_arr(char **map, int height)
{
	int		i;
	char	**mapp;

	mapp = malloc (sizeof(char *) * (height + 1));
	if (!mapp)
		return (NULL);
	i = 0;
	mapp[height] = NULL;
	while (i < height)
	{
		mapp[i] = ft_strdup(map[i]);
		i++;
	}
	return (mapp);
}

void	free_2d_arr(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int8_t	count_e_c(char **map, int height)
{
	int	i;
	int	j;
	int	e;
	int	c;

	e = 0;
	c = 0;
	i = -1;
	while (++i < height)
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
		return (1);
	return (0);
}

int	check_flood_fill(t_data *data)
{
	char	**map;

	map = dup_2d_arr(data->map, data->height);
	map[data->exit_pos.y][data->exit_pos.x] = 'X';
	flood_fill(map, data->player_pos.x,
		data->player_pos.y, data->height);
	if (!map)
		return (0);
	if (!count_e_c(map, data->height))
	{
		free_2d_arr(map);
		return (0);
	}
	free_2d_arr(map);
	return (1);
}
