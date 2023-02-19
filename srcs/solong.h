/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:41:20 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/18 19:16:47 by nakebli          ###   ########.fr       */
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
	void	*img_wall;
	char	**map;
	size_t	height;
	int		c;
	int		a;
	int		b;
	int		steps;
}	t_data;

int		check_map(t_data *data);
int		check_flood_fill(t_data *data);
void	draw_map(t_data *data);
int		fun(int keycode, t_data *data);
void	free_data(t_data *data);
void	top_assister(t_data *data);
void	bottom_assister(t_data *data);
void	left_assister(t_data *data);
void	right_assister(t_data *data);

#endif