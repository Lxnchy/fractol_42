# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 14:19:17 by jehubert          #+#    #+#              #
#    Updated: 2023/05/18 21:56:29 by jehubert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft/libft.a

SRCS = srcs/main.c \
	srcs/complex.c \
	srcs/mlx_utils.c \
	srcs/fract.c \
	srcs/atof.c \
	srcs/parsing.c \
	srcs/move.c \
	srcs/colors.c

OBJS = $(patsubst %,objs/%,$(notdir ${SRCS:.c=.o}))

CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O2 -O3 -march=native -funroll-loops -ffast-math -fomit-frame-pointer

objs/%.o : srcs/%.c
	${CC} ${CFLAGS} -c -Imlx $< -o $@

${NAME}:	$(OBJS) Makefile includes/fractol.h
	make --no-print-directory -C ./libft
	make --no-print-directory -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx_linux -L/usr/lib -Imlx_linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)
	echo "DONE !"

all: $(NAME)

re: fclean all

clean:
	make --no-print-directory -C ./libft clean
	make --no-print-directory -C ./mlx_linux clean
	rm -f $(OBJS)
	echo ".o FILES DELETED !"

fclean:
	make --no-print-directory -C ./libft fclean
	make --no-print-directory -C ./mlx_linux clean
	rm -f $(OBJS) $(NAME)
	echo ".o & EXECUTABLE DELETED !"

.PHONY: all clean fclean re
.SILENT: all clean fclean re $(NAME) $(OBJS)