/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:12:07 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/11 14:23:13 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../check/check.h"
#include <stdio.h>
// #include "check/check.h"
// #include <mlx.h>

char	**get_height(char *map_name, int *i)
{
	char	**map;
	int		fd;

	*i = 0;
	fd = open(map_name, O_RDWR);
	if (fd < 0)
		return (ft_putstr_fd("no map entered", 2), NULL);
	while (get_next_line(fd))
		*i += 1;
	map = (char **)malloc(sizeof(char *) * (*i + 1));
	if (!map)
		return (NULL);
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	int		fd;
	int		height;
	int		j;
	char	*map_name;
	char	**map;

	if (ac == 2)
	{
		map_name = av[1];
		map = get_height(map_name, &height);
		fd = open(map_name, O_RDWR);
		j = 0;
		while (j < height)
		{
			map[j] = ft_strtrim(get_next_line(fd), "\n");
			j++;
		}
		if (!check_map(map, height))
			return (ft_putstr_fd("BAD Map", 1), 0);
	}
	else
		ft_putstr_fd("syntax error", 1);
	return (0);
}
