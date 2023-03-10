/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:51:02 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/19 12:40:25 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (free((char *)s1), ft_strdup(s1));
	j = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[j]) && j > 0)
		j--;
	if (i > j)
		return (free((char *)s1), ft_strdup(""));
	s = malloc(j - i + 2);
	if (!s)
		return (free((char *)s1), NULL);
	ft_strlcpy(s, (char *)s1 + i, j - i + 2);
	free((char *)s1);
	return (s);
}
