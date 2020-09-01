/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_bsq.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/01 12:17:13 by obult         #+#    #+#                 */
/*   Updated: 2020/09/01 16:03:42 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

//prints everything untill a newline, then returns a pointer one place further
//added null terminator check in case the array does not end in "\n\0"
char	*ft_putstr_n(char *str)
{
	if (*str != '\n')
	{
		if (*str == '\0')
			return (0);
		write(1, str, 1);
		return (ft_putstr_n(str + 1));
	}
	return (str + 1);
}

//uses the ^ function to print till newline checks if next char is a nul terminator
//if not calls the function again on the previously returned pointer

//note to self, needs testing..
void	print_map(char *start)
{
	char *pnt;

	pnt = ft_putstr_n(start);
	if (!(pnt))
		return ;
	if (*pnt)
		print_map(pnt);	
}

//fills the location with the filled char from map info no matter whats in it
void	fill_square(t_data *md)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < md->size_tb)
	{
		j = 0;
		while (j < md->size_tb)
		{
			temp = md->ptr_tb + i * md->x + j;
			*temp = md->fill;
		}
	}
}

void	find_bsq(char *map, t_data *md)
{
	find_next_square(md);
	fill_square(md);
	print_map(map);
}
