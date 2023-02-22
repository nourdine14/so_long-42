/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:09:37 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/21 14:20:04 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	top_assister(t_data *data)
{
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/floor.xpm", &data->a, &data->b);
	if (!data->image)
		befor_exit("\x1B[31mERROR on image floor");
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	data->player_pos.y--;
	mlx_destroy_image(data->mlx, data->image);
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/player_top.xpm", &data->a, &data->b);
	if (!data->image)
		befor_exit("\x1B[31mERROR on image player_top");
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	mlx_destroy_image(data->mlx, data->image);
	ft_putstr_fd("step : ", 1);
	ft_putnbr_fd(data->steps++, 1);
	ft_putchar_fd('\n', 1);
}

void	bottom_assister(t_data *data)
{
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/floor.xpm", &data->a, &data->b);
	if (!data->image)
		befor_exit("\x1B[31mERROR on image floor");
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	data->player_pos.y++;
	mlx_destroy_image(data->mlx, data->image);
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/player_bottom.xpm", &data->a, &data->b);
	if (!data->image)
		befor_exit("\x1B[31mERROR on image player_bottom");
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	mlx_destroy_image(data->mlx, data->image);
	ft_putstr_fd("step : ", 1);
	ft_putnbr_fd(data->steps++, 1);
	ft_putchar_fd('\n', 1);
}

void	left_assister(t_data *data)
{
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/floor.xpm", &data->a, &data->b);
	if (!data->image)
		befor_exit("\x1B[31mERROR on image floor");
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	data->player_pos.x--;
	mlx_destroy_image(data->mlx, data->image);
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/player_left.xpm", &data->a, &data->b);
	if (!data->image)
		befor_exit("\x1B[31mERROR on image player_left");
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	mlx_destroy_image(data->mlx, data->image);
	ft_putstr_fd("step : ", 1);
	ft_putnbr_fd(data->steps++, 1);
	ft_putchar_fd('\n', 1);
}

void	right_assister(t_data *data)
{
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/floor.xpm", &data->a, &data->b);
	if (!data->image)
		befor_exit("\x1B[31mERROR on image floor");
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	data->player_pos.x++;
	mlx_destroy_image(data->mlx, data->image);
	data->image = mlx_xpm_file_to_image(data->mlx,
			"../images/player_right.xpm", &data->a, &data->b);
	if (!data->image)
		befor_exit("\x1B[31mERROR on image player_right");
	mlx_put_image_to_window(data->mlx, data->win, data->image,
		data->player_pos.x * SIZE, data->player_pos.y * SIZE);
	mlx_destroy_image(data->mlx, data->image);
	ft_putstr_fd("step : ", 1);
	ft_putnbr_fd(data->steps++, 1);
	ft_putchar_fd('\n', 1);
}

void	print_step(t_data *data)
{
	char		*s1;
	char		*s0;
	size_t		w;

	s0 = ft_itoa(data->steps);
	s1 = ft_strjoin(ft_strdup("steps : "), s0);
	free (s0);
	w = 0;
	data->image = mlx_xpm_file_to_image(data->mlx, "../images/black.xpm",
			&data->a, &data->b);
	while (w < (ft_strlen(data->map[0])) * SIZE)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image,
			w, (data->height * SIZE));
		w = w + 40;
	}
	mlx_string_put(data->mlx, data->win, 2, (data->height * SIZE)
		+ 1, 0x00FF00, s1);
	free(s1);
}
