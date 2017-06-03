# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etranchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 16:07:52 by etranchi          #+#    #+#              #
#    Updated: 2017/05/25 16:07:53 by etranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Werror -Wextra

SRC= main.c\
	utils.c\
	wall.c\
	color.c\
	draw.c\
	init.c\
	parsing.c\
	key.c\

NAME = wolf3d
CC = gcc
OBJ = $(SRC:.c=.o)
RM = rm -rf
INC = -I includes/
FRAME = -framework OpenGL -framework AppKit
FT = -L libft/ -lft
MLX = -L minilibx/ -lmlx
CG = \033[92m
CY =  \033[93m
CE = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[K$(CY)[WOLF3D] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	@make -C libft/ fclean
	@make -C libft/
	@$(CC)  $(FLAGS) $(FRAME) $(INC) -o $(NAME) $(OBJ) $(FT) $(MLX)
	@echo "\033[K$(CY)[WOLF3D] :$(CE) $(CG)Compiled WOLF-3D$(CE)";

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[WOLF3D] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

clean:
	@$(RM) $(OBJ)
	@echo "\033[K$(CY)[WOLF3D] :$(CE) $(CG)Cleaning Object files $(CE)";

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[K$(CY)[WOLF3D] :$(CE) $(CG)Cleaning WOLF3D $(CE)";

re: fclean all

.PHONY : all clean fclean re