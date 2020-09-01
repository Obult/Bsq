/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 12:15:07 by tel-bara      #+#    #+#                 */
/*   Updated: 2020/09/01 12:49:06 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_map_data
{
	int			x;
	int			y;
	char		empty;
	char		obs;
	char		fill;
	char		*ptr_tb;
	int			size_tb;
}				t_data;

int		open_file(char *file);
char	*import_map_to_string(char *file, int fd);
void	fill_map_string(char *str, int fd, int length);
int		validate_map(char *map, t_data *md);
int		consecutive_newlines(char *map);
int		end_newline(char *map);
int		lines_match(char **map_lines, int len, t_data *md);
int		ft_atoi_sorta(char *str, int end);
int		same_length(char **map_lines, int len, int lines);
int		duplicate_chars(char *map, int start);
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		check_square(char *check_this, int size, t_data *md);
int		search_bigger_square(char *check_this, int size, t_data *md);
void	find_next_square(t_data *md);
char	*ft_putstr_n(char *str);
void	print_map(char *start);
void	fill_square(t_data *md);
void	find_bsq(char *map, t_data *md);

#endif
