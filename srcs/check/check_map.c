/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:51:46 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/20 08:24:48 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static int	check_top_bottom(int c, char *map, size_t len, int h)
{
	int	j;

	if (ft_strlen(map) != len)
		return (0);
	if (c == 0 || c == h)
	{
		j = -1;
		while (map[++j])
		{
			if (map[j] != '1')
				return (0);
		}
	}
	return (1);
}

static int	check_rep(t_data *data, int i, int j)
{
	if (data->map[j][i] == 'E')
	{
		if (data->exit_pos.x == 0 && data->exit_pos.y == 0)
		{	
			data->exit_pos.x = i;
			data->exit_pos.y = j;
		}
		else
			return (0);
	}
	if (data->map[j][i] == 'P')
	{
		if (data->player_pos.x == 0 && data->player_pos.y == 0)
		{
			data->player_pos.x = i;
			data->player_pos.y = j;
		}
		else
			return (0);
	}
	if (data->map[j][i] == 'C')
		data->c++;
	return (1);
}

static int	check_content(char c)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		return (0);
	return (1);
}

static int	check_body(t_data *data)
{
	int		i;
	size_t	j;

	j = 0;
	data->player_pos.x = 0;
	data->player_pos.y = 0;
	data->exit_pos.x = 0;
	data->exit_pos.y = 0;
	while (j < data->height)
	{
		if (!check_top_bottom(j, data->map[j],
				ft_strlen(data->map[0]), data->height - 1))
			return (0);
		if (data->map[j][0] != '1'
			|| data->map[j][ft_strlen(data->map[j]) - 1] != '1')
			return (0);
		i = -1;
		while (data->map[j][++i])
		{
			if (!check_content(data->map[j][i]) || !check_rep(data, i, j))
				return (0);
		}
		j++;
	}
	return (1);
}

int	check_map(t_data *data)
{
	if (!check_body(data))
		return (0);
	return (1);
}
