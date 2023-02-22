/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:42:18 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/21 12:53:28 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	draw2(char c, t_data *data, int *w, int *h)
{
	if (c == 'P')
	{
		data->image = mlx_xpm_file_to_image(data->mlx,
				"../images/player_top.xpm", &data->a, &data->b);
		if (!data->image)
			befor_exit("\x1B[31mERROR on image player_top");
		mlx_put_image_to_window(data->mlx, data->win, data->image, *w, *h);
	}
	else if (c == 'E')
	{
		data->image = mlx_xpm_file_to_image(data->mlx,
				"../images/box.xpm", &data->a, &data->b);
		if (!data->image)
			befor_exit("\x1B[31mERROR on image box");
		mlx_put_image_to_window(data->mlx, data->win, data->image, *w, *h);
	}
}

void	draw(char c, t_data *data, int *w, int *h)
{
	if (c == '1')
	{
		data->image = mlx_xpm_file_to_image(data->mlx,
				"../images/tree.xpm", &data->a, &data->b);
		if (!data->image)
			befor_exit("\x1B[31mERROR on image tree");
		mlx_put_image_to_window(data->mlx, data->win, data->image, *w, *h);
	}
	else if (c == 'C')
	{
		data->image = mlx_xpm_file_to_image(data->mlx,
				"../images/collect.xpm", &data->a, &data->b);
		if (!data->image)
			befor_exit("\x1B[31mERROR on image collect");
		mlx_put_image_to_window(data->mlx, data->win, data->image, *w, *h);
	}
}

void	draw_map(t_data	*data)
{
	size_t	i;
	int		j;
	int		h;
	int		w;

	w = 0;
	h = 0;
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		w = 0;
		while (data->map[i][++j])
		{
			data->image = mlx_xpm_file_to_image(data->mlx,
					"../images/floor.xpm", &data->a, &data->b);
			if (!data->image)
				befor_exit("\x1B[31mERROR on image floor");
			mlx_put_image_to_window(data->mlx, data->win, data->image, w, h);
			draw(data->map[i][j], data, &w, &h);
			draw2(data->map[i][j], data, &w, &h);
			w += SIZE;
		}
		h += SIZE;
	}
}
