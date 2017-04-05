# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboiron <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 16:27:34 by cboiron           #+#    #+#              #
#    Updated: 2016/12/22 19:32:45 by cboiron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_format.c fill_list.c get_tetri.c solve_1.c solve_2.c \
solve_3.c main.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	gcc -o $(NAME) $(OBJ) libft/libft.a

%.o : %.c
	gcc -o $@ -c $< $(FLAG)

clean :
	rm -f $(OBJ)
	make clean -C ./libft
fclean : clean
	rm -f $(NAME)
	make fclean -C ./libft

re : fclean all
