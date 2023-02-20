/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:41:20 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/20 10:19:55 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

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
int		check_map(t_data *data);
int		check_flood_fill(t_data *data);

//	drawing
void	draw_map(t_data *data);

//	hook
int		fun(int keycode, t_data *data);

//	free data && exit
void	free_data(t_data *data);
void	free_2d_arr(char **map);
void	befor_exit(char **map, char *msg);

// drawing assisters
void	top_assister(t_data *data);
void	bottom_assister(t_data *data);
void	left_assister(t_data *data);
void	right_assister(t_data *data);

#endif