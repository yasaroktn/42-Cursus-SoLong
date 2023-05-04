# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokten <yokten@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 03:58:34 by yokten            #+#    #+#              #
#    Updated: 2023/05/04 05:46:22 by yokten           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./mandatory/so_long.c \
		./mandatory/add_malloc.c \
		./mandatory/control_error.c \
		./mandatory/control_error2.c \
		./mandatory/get_next_line.c \
		./mandatory/map_managment.c \
		./mandatory/move_char.c \
		./mandatory/render_map.c \
		./mandatory/utils/get_next_line_utils.c \
		./mandatory/utils/so_long_utils.c \
		
BSRCS =	./bonus/mandatory/so_long.c \
		./bonus/mandatory/add_malloc.c \
		./bonus/mandatory/control_error.c \
		./bonus/mandatory/control_error2.c \
		./bonus/mandatory/get_next_line.c \
		./bonus/mandatory/map_managment.c \
		./bonus/mandatory/move_char.c \
		./bonus/mandatory/render_map.c \
		./bonus/mandatory/utils/get_next_line_utils.c \
		./bonus/mandatory/utils/so_long_utils.c \
		
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx_opengl_20191021 -lmlx
MLX = ./minilibx_opengl_20191021/libmlx.a
RM = rm -rf
LIBC = ar -rcs

all: $(MLX) $(NAME)

$(NAME): $(SRCS) $(MLX)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) -o ./mandatory/$(NAME)

bonus : $(BSRCS) $(MLX)
	@gcc $(CFLAGS) $(LFLAGS) $(BSRCS) -o ./bonus/mandatory/$(NAME)

$(MLX) :
	@make -C ./minilibx_opengl_20191021

clean:
	@make clean -C ./minilibx_opengl_20191021

fclean: clean
	@rm -rf ./mandatory/$(NAME)
	@rm -rf ./bonus/mandatory/$(NAME)
	@make clean -C ./minilibx_opengl_20191021

re: fclean all

.PHONY: all bonus clean fclean re .c.o