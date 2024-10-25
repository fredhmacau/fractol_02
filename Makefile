# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmacau <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 18:05:51 by fmacau            #+#    #+#              #
#    Updated: 2024/10/25 20:53:14 by fmacau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
RM = rm -f
FLAGS = -Wall -Werror -Wextra
CC = cc
INCLUDE = -I/usr/include \
		 -Imlx_linux -03 \

LIBFT = libft/
MINILIBX = minilibx-linux/

EXTRAFLAGS = -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = src/fractol.c \
	src/utils/ft_print_help.c \
	src/ft_fractol_init.c \
	src/ft_render.c \
	src/utils/ft_scale.c \
	src/ft_events.c \
	src/utils/ft_strod.c \
	src/utils/ft_check_params.c \

OBJ = $(SRC:.o=.c)

%.o:%.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
		@make -sC $(LIBFT)
		@chmod 777 $(MINILIBX)/./configure
		@make -sC $(MINILIBX)
		$(CC) $(FLAGS) $(OBJ) -Lminilibx-linux $(EXTRAFLAGS) -o $(NAME) -L libft/ -lft

clean: 
		${RM} ${OBJ_1} ${OBJ_2} ${NAME}
		@cd ${LIBFT} && ${MAKE} clean

fclean: clean
		${RM} ${NAME}
		@cd ${LIBFT} && ${MAKE} fclean

re: fclean all
