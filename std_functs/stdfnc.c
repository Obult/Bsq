/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stdfnc.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 14:42:44 by obult         #+#    #+#                 */
/*   Updated: 2020/08/31 14:57:53 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	if (*str != 0)
	{
		write(1, str, 1);
		ft_putstr(str + 1);
	}
}

//prints everything untill a newline, then returns a pointer one place further
//added null terminator check in case the array does not end in "\n\0"

//is different than the version in check_squares.c

char	*ft_putstr_n(char *str)
{
	if (*str != '\n' && *str != '\0')
	{
		write(1, str, 1);
		return (ft_putstr(str + 1));
	}
	return (str + 1);
}
