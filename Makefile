# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 12:02:48 by tamehri           #+#    #+#              #
#    Updated: 2024/04/02 16:38:51 by tamehri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	src/fdf_main.c \
			src/key_hook.c\
			util/fdf_err.c

GREEN		=	'\033[32m'
NONE		=	'\033[0m'
CC			=	cc
NAME		=	zship
HEADER		=	src/fdf.h src/fdf_struct.h
OBJ			=	$(SRC:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L /usr/local/lib -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS)
	@echo $(GREEN) "compilation done\n" $(NONE)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN) "... Compiling\t$<\t[OK]" $(RESET)

clean:
	@rm -f $(OBJ)
	@echo $(GREEN) "clean done\n" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@echo $(GREEN) "fclean done\n" $(NONE)

re: fclean all
	@echo $(GREEN) "re done\n" $(NONE)

.PHONY: clean
