/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_square.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 12:37:54 by obult         #+#    #+#                 */
/*   Updated: 2020/08/31 18:32:39 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

struct map_info
{
	int		size_x;
	int		size_y;
	char	clear;
	char	filled;
	char	obstacle;
}
struct map_info s_map_info;

//returns a 0 if it couldnt make size square
int		check_square(char *check_this, int size, struct map_info s_map_info)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0
		while (j < size)
		{
			temp = check_this + i * s_map_info.size_x + j;
			if (*temp != s_map_info.clear)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//returns the size of the biggest square it could make in the given location
int		search_bigger_square(char *check_this, int size, struct map_info s_map_info)
{
	if (check_square(*check_this, size, s_map_info))
		return (search_bigger_square(*check_this, size + 1, s_map_info));
	return (size - 1);
}

//checks per location if we can make a bigger square than our square to beat (size_tb)
//returns the location where it could make the biggest square as a pointer to the array
//size_tb is given as a pointer so it can be changed from within the function and used above it
char	*find_next_square(char *pnt_tb, int *size_tb, struct map_info s_map_info)
{
	char *loca;

	loca = pnt_tb;
	while (*loca)
	{
		if (*size_tb < search_bigger_square(loca, *size_tb + 1, s_map_info))
		{
			*size_tb = search_bigger_square(loca, *size_tb + 1, s_map_info);
			pnt_tb = loca;
		}
		loca++;git@vogsphere-v2.codam.nl:vogsphere/intra-uuid-a4198d8a-e37f-44fb-8b46-199dbfa30db4-3294705
	}
	return (pnt_tb);
}

//fills the location with the filled char from map info no matter whats in it
void	fill_square(char *start, int size, struct map_info s_map_info)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			temp = start + i * s_map_info.size_x + j;
			*temp = s_map_info.filled;
		}
	}
}

//prints everything untill a newline, then returns a pointer one place further
//added null terminator check in case the array does not end in "\n\0"
char	*ft_putstr_n(char *str)
{
	if (*str != '\n')
	{
		if (*str == '\0')
			return (0);
		write(1, str, 1);
		return (ft_putstr(str + 1));
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
