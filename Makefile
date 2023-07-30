# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hstein <hstein@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 16:17:33 by hstein            #+#    #+#              #
#    Updated: 2023/07/29 23:57:45 by hstein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := so_long
CFLAGS  := -Wextra -Wall -Werror -g -v
LFLAGS  := -ldl -lglfw -lpthread -lm
LIBMLX  := ./MLX42/build
HEADERS := -I ./include -I $(LIBMLX)/include
LIBS    := $(LIBMLX)/libmlx42.a
LIBFT   := libft/libft.a
SRCS    :=	miniaudio.c				\
			main.c 					\
			error_checks_1.c		\
			error_checks_2.c		\
			key_handling_1.c 		\
			key_handling_2.c 		\
			mlx_func_1.c			\
			mlx_func_2.c			\
			mlx_func_3.c			\
			mlx_func_4.c			\
			cluster_1.c				\
			cluster_2.c				\
			cluster_hook_1.c		\
			cluster_hook_2.c		\
			cluster_hook_3.c		\
			print_1.c				\
			print_2.c				\
			pics_1.c				\
			pics_2.c				\
			add_functions_1.c		\
			add_functions_2.c		\
			add_functions_3.c		\
			add_functions_4.c		\
			add_functions_5.c		\
			utils_1.c				\
			utils_2.c				\
			utils_3.c				\
			utils_4.c				\
			enemy_1.c				\
			enemy_2.c				\
			enemy_3.c				\
			enemy_max_1.c				\
			enemy_max_2.c
OBJS    := ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	make -C libft
	@if [ ! -d "./MLX42/" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	@if [ ! -d "./MLX42/build" ]; then \
		cd ./MLX42 && cmake -B build && cmake --build build -j4; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIBS) $(LIBFT) -o $(NAME) $(HEADERS)

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBMLX)/libmlx42.a
	rm -rf MLX42

re: fclean all

.PHONY: all clean fclean re libmlx
