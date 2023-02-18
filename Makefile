# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 14:19:17 by jehubert          #+#    #+#              #
#    Updated: 2023/02/18 14:33:53 by jehubert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = libft/libft.a

SRCS = srcs/main.c

OBJS = $(patsubst %,objs/%,$(notdir ${SRCS:.c=.o}))

CFLAGS = -Wall -Wextra -Werror

objs/%.o : srcs/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	$(OBJS)
	make --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	echo "DONE !"

all: $(NAME)

clean:
	make --no-print-directory -C ./libft clean
	rm -f $(OBJS)
	echo ".o FILES DELETED !"

fclean:
	make --no-print-directory -C ./libft fclean
	rm -f $(OBJS) $(NAME)
	echo ".o & EXECUTABLE DELETED"

.PHONY: all clean fclean re
.SILENT: all clean fclean re $(NAME) $(OBJS)