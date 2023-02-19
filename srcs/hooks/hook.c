/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:27:05 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/19 20:38:36 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	bottom(t_data *data)
{
	if (data->map[data->player_pos.y + 1][data->player_pos.x] != '1')
	{
		if (data->map[data->player_pos.y + 1][data->player_pos.x] == 'E'
			&& data->c == 0)
			exit(0);
		else
		{
			if (data->map[data->player_pos.y + 1][data->player_pos.x] == 'C')
			{
				data->map[data->player_pos.y + 1][data->player_pos.x] = '0';
				data->c--;
			}
			if (data->map[data->player_pos.y + 1][data->player_pos.x] != 'E')
				bottom_assister(data);
		}
	}
}

void	top(t_data *data)
{
	if (data->map[data->player_pos.y - 1][data->player_pos.x] != '1')
	{
		if (data->map[data->player_pos.y - 1][data->player_pos.x] == 'E'
			&& data->c == 0)
		{
			free_data(data);
			exit(0);
		}
		else
		{
			if (data->map[data->player_pos.y - 1][data->player_pos.x] == 'C')
			{
				data->map[data->player_pos.y - 1][data->player_pos.x] = '0';
				data->c--;
			}
			if (data->map[data->player_pos.y - 1][data->player_pos.x] != 'E')
				top_assister(data);
		}
	}
}

void	left(t_data *data)
{
	if (data->map[data->player_pos.y][data->player_pos.x - 1] != '1')
	{
		if (data->map[data->player_pos.y][data->player_pos.x - 1] == 'E'
			&& data->c == 0)
			exit(0);
		else
		{
			if (data->map[data->player_pos.y][data->player_pos.x - 1] == 'C')
			{
				data->map[data->player_pos.y][data->player_pos.x - 1] = '0';
				data->c--;
			}
			if (data->map[data->player_pos.y][data->player_pos.x - 1] != 'E')
				left_assister(data);
		}
	}
}

void	right(t_data *data)
{
	if (data->map[data->player_pos.y][data->player_pos.x + 1] != '1')
	{
		if (data->map[data->player_pos.y][data->player_pos.x + 1] == 'E'
			&& data->c == 0)
			exit(0);
		else
		{
			if (data->map[data->player_pos.y][data->player_pos.x + 1] == 'C')
			{
				data->map[data->player_pos.y][data->player_pos.x + 1] = '0';
				data->c--;
			}
			if (data->map[data->player_pos.y][data->player_pos.x + 1] != 'E')
				right_assister(data);
		}
	}
}

int	fun(int keycode, t_data *data)
{
	if (keycode == 1 || keycode == 125)
		bottom(data);
	if (keycode == 13 || keycode == 126)
		top(data);
	if (keycode == 0 || keycode == 123)
		left(data);
	if (keycode == 2 || keycode == 124)
		right(data);
	if (keycode == 53)
		exit(0);
	return (1);
}
