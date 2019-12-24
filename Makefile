# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 06:48:20 by hlourtie          #+#    #+#              #
#    Updated: 2019/08/28 19:48:27 by hlourtie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = file calcul help file2 errors free
MAIN = main.c
INC = ./includes/
SRCDIR = ./sources/
CFILES = $(patsubst %, $(SRCDIR)%.c, $(SRC))
all: $(NAME)
$(NAME): 
	gcc -Wall -Wextra -Werror -o$(NAME) $(MAIN) $(CFILES) -I $(INC)

clean:
	/bin/rm -f 

fclean:
	/bin/rm -f $(NAME)
re: fclean all
