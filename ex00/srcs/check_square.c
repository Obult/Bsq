/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 12:37:54 by obult         #+#    #+#                 */
/*   Updated: 2020/09/01 16:00:51 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

//returns a 0 if it couldnt make size square
int		check_square(char *check_this, int size, t_data *md)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			temp = check_this + i * md->x + j;
			if (*temp != md->empty)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//returns the size of the biggest square it could make in the given location
int		search_bigger_square(char *check_this, int size, t_data *md)
{
	if (check_square(check_this, size, md))
		return (search_bigger_square(check_this, size + 1, md));
	return (size - 1);
}

//checks per location if we can make a bigger square than our square to beat (size_tb)
//returns the location where it could make the biggest square as a pointer to the array
//size_tb is given as a pointer so it can be changed from within the function and used above it
void	find_next_square(t_data *md)
{
	char *loca;

	loca = md->ptr_tb;
	while (*loca)
	{
		if (md->size_tb < search_bigger_square(loca, md->size_tb + 1, md))
		{
			md->size_tb = search_bigger_square(loca, md->size_tb + 1, md);
			md->ptr_tb = loca;
		}
		loca++;
	}
}
