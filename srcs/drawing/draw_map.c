/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:42:18 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/15 20:07:32 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	draw_map(t_data	*data)
{
	int	i;
	int	j;
	int	h;
	int	w;

	w = 0;
	h = 0;
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		w = 0;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
			{
				data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/wall.xpm", &data->a, &data->b);
				mlx_put_image_to_window(data->mlx, data->win,data->img_wall, w, h);
			}
			if (data->map[i][j] == '0' || data->map[i][j] == 'P' || data->map[i][j] == 'E' || data->map[i][j] == 'C')
			{
				data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/f.xpm", &data->a, &data->b);
				mlx_put_image_to_window(data->mlx, data->win,data->img_wall, w, h);
			}
			if (data->map[i][j] == 'C')
			{
				data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/collect.xpm", &data->a, &data->b);
				mlx_put_image_to_window(data->mlx, data->win,data->img_wall, w, h);
			}
			if (data->map[i][j] == 'P')
			{
				data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/player.xpm", &data->a, &data->b);
				mlx_put_image_to_window(data->mlx, data->win,data->img_wall, w, h);
			}
			if (data->map[i][j] == 'E')
			{
				data->img_wall = mlx_xpm_file_to_image(data->mlx, "../images/p.xpm", &data->a, &data->b);
				mlx_put_image_to_window(data->mlx, data->win,data->img_wall, w, h);
			}
			w += SIZE;
		}
		h += SIZE;
	}
}
	// mlx_hook(data->win, 17, 0, &red_cross, NULL);
