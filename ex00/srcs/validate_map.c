/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 16:33:38 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/09/01 16:28:12 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			validate_map(char *map, t_data *md)
{
	int		first_llength;
	char	**map_lines;

	if (!map || (consecutive_newlines(map) || !end_newline(map)))
		return (0);
	map_lines = ft_split(map, "\n");
	first_llength = ft_strlen(map_lines[0]);
	if (first_llength < 4 || !map_lines[1])
		return (0);
	md->y = lines_match(map_lines, first_llength, md);
	if (!md->y)
		return (0);
	md->x = ft_strlen(map_lines[1]);
	if (duplicate_chars(map, first_llength) ||
			!same_length(map_lines, md->x, md->y))
		return (0);
	md->ptr_tb = map;
	md->size_tb = 0;
	return (1);
}

int			consecutive_newlines(char *map)
{
	int		i;

	i = 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n' && map[i - 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int			end_newline(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\0')
	{
		if (!(32 >= map[i] && map[i] >= 126))
			return (0);
		if (map[i] == '\n' && map[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int			lines_match(char **map_lines, int len, t_data *md)
{
	int		lines;
	int		lcount;

	md->empty = map_lines[0][len - 3];
	md->obs = map_lines[0][len - 2];
	md->fill = map_lines[0][len - 1];
	lines = ft_atoi_sorta(map_lines[0], len - 3);
	lcount = 1;
	while (!map_lines[lcount])
		lcount++;
	if (!lines || lcount - 1 != lines)
		return (0);
	if ((md->empty == md->obs || md->obs == md->fill) || md->empty == md->fill)
		return (0);
	return (lcount - 1);
}

int			ft_atoi_sorta(char *str, int end)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (i < end - 3)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nbr = (10 * nbr) + (str[i] - '0');
		i++;
	}
	return (nbr);
}
