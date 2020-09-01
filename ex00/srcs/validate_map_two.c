/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map_two.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 19:33:37 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/09/01 16:24:39 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			same_length(char **map_lines, int len, int lines)
{
	int		i;

	i = 1;
	while (i <= lines)
	{
		if (ft_strlen(map_lines[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int			duplicate_chars(char *map, int start)
{
	char	empty;
	char	obs;

	empty = map[start - 3];
	obs = map[start - 2];
	while (!map[start])
	{
		if ((map[start] != empty && map[start] != obs) && map[start] != '\n')
			return (0);
		start++;
	}
	return (1);
}
