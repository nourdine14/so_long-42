/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:27:05 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/16 21:47:04 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void    bottom(t_data *data)
{
    if (data->map[data->player_pos.y + 1][data->player_pos.x] != '1')
    {
        if (data->map[data->player_pos.y + 1][data->player_pos.x] == 'E' && data->c == 0)
        {
            exit(0);
        }
        else
        {
            if (data->map[data->player_pos.y + 1][data->player_pos.x] == 'C')
                data->c--;
            if (data->map[data->player_pos.y + 1][data->player_pos.x] != 'E')
            {
                data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
                mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
                data->player_pos.y++;
                data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
                mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
            }
        }
    }
}

void    top(t_data *data)
{
    if (data->map[data->player_pos.y - 1][data->player_pos.x] != '1')
    {
        if (data->map[data->player_pos.y - 1][data->player_pos.x] == 'E' && data->c == 0)
        {
            exit(0);
        }
        else
        {
            if (data->map[data->player_pos.y - 1][data->player_pos.x] == 'C')
                data->c--;
            if (data->map[data->player_pos.y - 1][data->player_pos.x] != 'E')
            {
                data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
                mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
                data->player_pos.y--;
                data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
                mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
            }
        }
    }
}

void    left(t_data *data)
{
        if (data->map[data->player_pos.y][data->player_pos.x - 1] != '1')
        {
            if (data->map[data->player_pos.y][data->player_pos.x - 1] == 'E' && data->c == 0)
            {
                exit(0);
            }
            else
            {
                if (data->map[data->player_pos.y][data->player_pos.x - 1] == 'C')
                    data->c--;
                if (data->map[data->player_pos.y][data->player_pos.x - 1] != 'E')
                {
                    data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
			        mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
                    data->player_pos.x--;
                    data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
			        mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
                }
            }
        }
}

void    right(t_data *data)
{
    if (data->map[data->player_pos.y][data->player_pos.x + 1] != '1')
    {
        if (data->map[data->player_pos.y][data->player_pos.x + 1] == 'E' && data->c == 0)
        {
            exit(0);
        }
        else
        {
            if (data->map[data->player_pos.y][data->player_pos.x + 1] == 'C')
                data->c--;
            if (data->map[data->player_pos.y][data->player_pos.x + 1] != 'E')
            {
                data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
                mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
                data->player_pos.x++;
                data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
                mlx_put_image_to_window(data->mlx, data->win,data->img_wall, data->player_pos.x * SIZE,data->player_pos.y * SIZE);
            }
        }
    }
}


int fun(int keycode, t_data *data)
{
    if (keycode == 1 || keycode == 125)
        bottom(data);
    if (keycode == 13 || keycode == 126)
        top(data);
    if (keycode == 0 || keycode == 123)
        left(data);
    if (keycode == 2 || keycode == 124)
        right(data);
    if(keycode == 53)
        exit(0);
    return 1;
}