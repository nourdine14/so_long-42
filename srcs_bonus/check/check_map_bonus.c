/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:51:46 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/21 14:43:59 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

static void	check_top_bottom(int c, char *map, size_t len, int h)
{
	int	j;

	if (ft_strlen(map) != len)
		befor_exit("\x1B[31mERROR : map not rectangular");
	if (c == 0 || c == h)
	{
		j = -1;
		while (map[++j])
		{
			if (map[j] != '1')
				befor_exit("\x1B[31mERROR : map not surreounded by walls [1]");
		}
	}
}

static void	check_rep(t_data *data, int i, int j)
{
	if (data->map[j][i] == 'E')
	{
		if (data->exit_pos.x == 0 && data->exit_pos.y == 0)
		{	
			data->exit_pos.x = i;
			data->exit_pos.y = j;
		}
		else
			befor_exit("\x1B[31mERROR : there is more than 1 Exit");
	}
	if (data->map[j][i] == 'P')
	{
		if (data->player_pos.x == 0 && data->player_pos.y == 0)
		{
			data->player_pos.x = i;
			data->player_pos.y = j;
		}
		else
			befor_exit("\x1B[31mERROR : there is more than 1 Player");
	}
	if (data->map[j][i] == 'C')
		data->c++;
}

static void	check_content(char c)
{
	if (c != '1' && c != '0' && c != 'E' && c != 'P' && c != 'C')
		befor_exit("\x1B[31mERROR : map content unknown");
}

void	check_map(t_data *data)
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
		check_top_bottom(j, data->map[j],
			ft_strlen(data->map[0]), data->height - 1);
		if (data->map[j][0] != '1'
			|| data->map[j][ft_strlen(data->map[j]) - 1] != '1')
			befor_exit("\x1B[31mERROR : map not surreounded by walls [1]");
		i = -1;
		while (data->map[j][++i])
		{
			check_rep(data, i, j);
			check_content(data->map[j][i]);
		}
		j++;
	}
	if (data->player_pos.x == 0 || data->exit_pos.x == 0 || data->c == 0)
		befor_exit("\x1B[31mERROR : map is missing a content[P, E, or C]");
}
