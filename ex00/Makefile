# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tel-bara <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/27 13:32:15 by tel-bara      #+#    #+#                  #
#    Updated: 2020/09/01 15:56:33 by obult         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= BSQ

SRCS	= srcs/check_square.c srcs/find_bsq.c srcs/ft_split.c srcs/import_map.c srcs/main.c srcs/utilities.c srcs/validate_map_two.c srcs/validate_map.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -f

HEADER	= -Iincludes

CFLAGS	= -Wall -Wextra -Werror

all: ${NAME}

.c.o:
			${CC} -c ${CFLAGS} ${HEADER} $< -o ${<:.c=.o}
clean:
			${RM}  ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

.PHONY: all clean fclean re
