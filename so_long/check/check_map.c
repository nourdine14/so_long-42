/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:51:46 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/11 16:40:53 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static int	check_top_button(int c, char *map, size_t len, int h)
{
	int	j;

	if (ft_strlen(map) != len)
		return (0);
	j = -1;
	if (c == 0 || c == h)
	{
		while (map[j])
		{
			if (map[j] != '1')
				return (0);
		}
	}
	return (1);
}

static int	check_body(char **map, int height)
{
	int	j;
	int	e;
	int	p;
	int	c;
	int	i;

	j = -1;
	e = 0;
	p = 0;
	c = 0;
	while (map[++j])
	{
		if (!check_top_button(j, map[j], ft_strlen(map[0]), height - 1))
			return (0);
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			return (0);
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'E'
				&& map[j][i] != 'P' && map[j][i] != 'C')
				return (0);
			if (map[j][i] == 'E')
				e++;
			if (map[j][i] == 'P')
				p++;
			if (map[j][i] == 'C')
				c++;
		}
	}
	if (e != 1 || p != 1 || c == 0)
		return (0);
	return (1);
}

int	check_map(char **map, int height)
{
	int	ret;

	ret = check_body(map, height);
	if (!ret)
		return (0);
	return (1);
}
