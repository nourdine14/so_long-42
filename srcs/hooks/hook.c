/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:27:05 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/15 19:55:09 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void    bottom(t_data *data)
{
    if (data->map[data->player_pos.y + 1][data->player_pos.x] != '1')
    {
        if (data->map[data->player_pos.y + 1][data->player_pos.x] == 'C')
            data->c--;
        data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
		mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
        data->player_pos.y++;
        data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
		mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
        if (data->c == 0)
            exit(0);
    }
}

void    top(t_data *data)
{
    if (data->map[data->player_pos.y - 1][data->player_pos.x] != '1')
    {
        if (data->map[data->player_pos.y - 1][data->player_pos.x] == 'C')
            data->c--;
        data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
		mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
        data->player_pos.y--;
        data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
		mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
        if (data->c == 0)
            exit(0);
    }
}

void    left(t_data *data)
{
        if (data->map[data->player_pos.y][data->player_pos.x - 1] != '1')
        {
            if (data->map[data->player_pos.y][data->player_pos.x - 1] == 'C')
                data->c--;
            data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
			mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
            data->player_pos.x--;
            data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
			mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
            if (data->c == 0)
                exit(0);
        }
}

void    right(t_data *data)
{
    if (data->map[data->player_pos.y][data->player_pos.x + 1] != '1')
    {
        if (data->map[data->player_pos.y][data->player_pos.x + 1] == 'C')
            data->c--;
        data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
		mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
        data->player_pos.x++;
        data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
		mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
        if (data->c == 0)
            exit(0);
    }
}


int fun(int keycode, t_data *data)
{
    if (keycode == 1)
        bottom(data);
    if (keycode == 13)
        top(data);
    if (keycode == 0)
        left(data);
    if (keycode == 2)
        right(data);
    if(keycode == 53)
        exit(0);
    return 1;
}