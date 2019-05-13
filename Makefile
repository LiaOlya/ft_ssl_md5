#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oltkache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 15:33:49 by oltkache          #+#    #+#              #
#    Updated: 2018/05/20 15:33:50 by oltkache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ssl

SRC = main.c 

OBJ = main.o 

FLAGS = -Wall -Wextra -Werror

all: sub $(NAME)
	
sub:
	$(MAKE) -C ./libft

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) libft/libft.a

clean: subcl
	rm -f $(OBJ)

subcl:
	$(MAKE) -C ./libft clean

fclean: subf clean
	rm -f $(NAME)

subf:
	$(MAKE) -C ./libft fclean

re: fclean all

%.o : %.c
	gcc $(FLAGS) -c $<