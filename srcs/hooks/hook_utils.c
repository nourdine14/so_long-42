/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:09:37 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/19 20:14:30 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	top_assister(t_data *data)
{
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/floor.xpm", &data->a, &data->b);
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	data->player_pos.y--;
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/player_top.xpm", &data->a, &data->b);
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	ft_putstr_fd("step : ", 1);
	ft_putnbr_fd(data->steps++, 1);
	ft_putchar_fd('\n', 1);
}

void	bottom_assister(t_data *data)
{
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/floor.xpm", &data->a, &data->b);
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	data->player_pos.y++;
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/player_bottom.xpm", &data->a, &data->b);
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	ft_putstr_fd("step : ", 1);
	ft_putnbr_fd(data->steps++, 1);
	ft_putchar_fd('\n', 1);
}

void	left_assister(t_data *data)
{
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/floor.xpm", &data->a, &data->b);
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	data->player_pos.x--;
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/player_left.xpm", &data->a, &data->b);
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	ft_putstr_fd("step : ", 1);
	ft_putnbr_fd(data->steps++, 1);
	ft_putchar_fd('\n', 1);
}

void	right_assister(t_data *data)
{
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/floor.xpm", &data->a, &data->b);
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	data->player_pos.x++;
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/player_right.xpm", &data->a, &data->b);
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	ft_putstr_fd("step : ", 1);
	ft_putnbr_fd(data->steps++, 1);
	ft_putchar_fd('\n', 1);
}
