/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:44:50 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/21 12:53:32 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	flood_fill_exit(char **map, size_t x, size_t y, size_t height)
{
	if (x < ft_strlen(map[0]) && y < height
		&& map[y][x] != '1' && map[y][x] != 'X')
	{
		map[y][x] = 'X';
		flood_fill_exit(map, x + 1, y, height);
		flood_fill_exit(map, x - 1, y, height);
		flood_fill_exit(map, x, y + 1, height);
		flood_fill_exit(map, x, y - 1, height);
	}
}

void	flood_fill_collect(char **map, size_t x, size_t y, size_t height)
{
	if (x < ft_strlen(map[0]) && y < height
		&& map[y][x] != '1' && map[y][x] != 'X' && map[y][x] != 'E')
	{
		map[y][x] = 'X';
		flood_fill_collect(map, x + 1, y, height);
		flood_fill_collect(map, x - 1, y, height);
		flood_fill_collect(map, x, y + 1, height);
		flood_fill_collect(map, x, y - 1, height);
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

int	count_e_c(char **map, int height, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == c)
				count++;
		}
	}
	if (count == 0)
		return (1);
	return (0);
}
