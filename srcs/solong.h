/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:41:20 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/11 19:07:45 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_pos	player_pos;
	t_pos	exit_pos;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_col;
	void	*img_exit;
	char	**map;
	int		height;
	int		c;

}	t_data;

int	check_map(t_data *data);
int	pathe_valid(char **map, int height);

#endif
