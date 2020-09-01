/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 14:45:32 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/09/01 16:05:19 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putstr("map error\n");
	return (fd);
}

char		*import_map_to_string(char *file, int fd)
{
	char	buffer[2];
	int		length;
	char	*str;

	length = 0;
	while (read(fd, buffer, 1))
		length++;
	str = (char*)malloc((length + 1) * sizeof(char));
	str[length] = '\0';
	close(fd);
	open(file, O_RDONLY);
	fill_map_string(str, fd, length);
	return (str);
}

void		fill_map_string(char *str, int fd, int length)
{
	char	buffer[2];
	int		i;

	i = 0;
	while (i < length)
	{
		read(fd, buffer, 1);
		str[i] = buffer[0];
		i++;
	}
	str[i] = '\0';
	close(fd);
}
