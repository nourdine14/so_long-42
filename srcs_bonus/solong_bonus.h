/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:41:20 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/21 12:59:57 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <fcntl.h>
# include "../libft/libft.h"
# include <limits.h>

# define SIZE 40

//	data
typedef struct s_pos
{
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_pos	player_pos;
	t_pos	exit_pos;
	void	*image;
	char	**map;
	size_t	height;
	int		c;
	int		a;
	int		b;
	int		steps;
}	t_data;

//	check map
void	check_map(t_data *data);
void	check_flood_fill(t_data *data);

// flood fill utils
void	flood_fill_exit(char **map, size_t x, size_t y, size_t height);
void	flood_fill_collect(char **map, size_t x, size_t y, size_t height);
char	**dup_2d_arr(char **map, int height);
void	free_2d_arr(char **map);
int		count_e_c(char **map, int height, char c);

//	drawing
void	draw_map(t_data *data);

//	hook
int		fun(int keycode, t_data *data);

//	free data && exit
void	free_data(t_data *data);
void	free_2d_arr(char **map);
void	befor_exit(char *msg);

// drawing assisters
void	print_step(t_data *data);
void	top_assister(t_data *data);
void	bottom_assister(t_data *data);
void	left_assister(t_data *data);
void	right_assister(t_data *data);
void	print_step(t_data *data);

#endif