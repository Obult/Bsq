/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 15:12:11 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/09/01 11:56:01 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			main(int argc, char **argv)
{
	int			i;
	int			fd;
	char		*map;
	t_data		md;

	i = 1;
	while (i < argc)
	{
		while (i)
		{
		fd = open_file(argv[i]);
		if (fd == -1)
			break ;
		map = import_map_to_string(argv[i], fd);
		if (!validate_map(map, &md))
			break ;
		find_bsq(map, &md);
		}
		i++;
	}
	exit (0);
}
