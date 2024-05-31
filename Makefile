# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myassine <myassine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 18:16:48 by myassine          #+#    #+#              #
#    Updated: 2024/05/31 23:47:06 by myassine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -f

SRC 		=	main.c \
				check_and_pars.c \
				check.c \
				error.c \
				toolbox.c \
				toolbox_1.c \
				toolbox_2.c \
				toolbox_3.c \
				fill_map.c \
				init_data.c \
				split.c \
				free.c
				

	
OBJ 		= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		gcc ${CFLAGS} -o $(NAME) ${OBJ}

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
