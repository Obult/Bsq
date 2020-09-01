/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/28 14:19:16 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/08/31 19:56:05 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			sep(int i, char *str, char *charset)
{
	int j;

	j = 0;
	if (charset[j] == '\0')
		return (0);
	while (str[i] != charset[j] && charset[j] != '\0')
	{
		if (charset[j + 1] == '\0')
			return (0);
		j++;
	}
	return (1);
}

void		array_index(char *str, char *charset, char **array, int size)
{
	int	i;
	int	count;
	int	index;

	i = 0;
	index = 0;
	while (str[i] != '\0' && index < size)
	{
		count = 0;
		while (!sep(i, str, charset))
		{
			count++;
			i++;
		}
		if (count != 0)
		{
			array[index] = (char*)malloc((count + 1) * sizeof(char));
			array[index][count] = '\0';
			index++;
		}
		while (sep(i, str, charset) && str[i] != '\0')
			i++;
	}
}

int			string_counter(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!sep(i, str, charset) && str[i] != '\0')
	{
		i++;
		count++;
	}
	while (str[i] != '\0')
	{
		if (!sep(i, str, charset) && sep(i - 1, str, charset))
			count++;
		i++;
	}
	return (count);
}

void		fill_array(char *str, char *charset, char **array)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = -1;
	if (!sep(i[0], str, charset) && str[i[0]] != '\0')
	{
		array[0][0] = str[0];
		i[2]++;
		i[0]++;
		i[1]++;
	}
	while (str[i[0]] != '\0')
	{
		if (!sep(i[0], str, charset) && sep(i[0] - 1, str, charset))
			i[2]++;
		if (!sep(i[0], str, charset))
		{
			array[i[2]][i[1]] = str[i[0]];
			i[1]++;
		}
		else
			i[1] = 0;
		i[0]++;
	}
}

char		**ft_split(char *str, char *charset)
{
	int		size;
	char	**array;
	int		i;

	i = 0;
	size = string_counter(str, charset);
	array = malloc((size + 1) * sizeof(char *));
	array[size] = (char*)malloc(1 * sizeof(char));
	array[size] = 0;
	if (size == 1 && charset[0] == '\0')
	{
		while (str[i] != '\0')
			i++;
		array[0] = (char*)malloc((i + 1) * sizeof(char));
		array[0] = str;
		return (array);
	}
	array_index(str, charset, array, size);
	fill_array(str, charset, array);
	return (array);
}
