# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmacau <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/20 18:05:51 by fmacau            #+#    #+#              #
#    Updated: 2024/10/20 18:05:53 by fmacau           ###   ########.fr        #
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

SRC = srcs/fractol.c \
	# srcs/ft_draw_julia.c \
	# srcs/ft_draw_pixel.c \
	# srcs/ft_get_color.c \
	# srcs/ft_init_fractol.c \
	# srcs/ft_print_help.c \
	# srcs/ft_strod.c \

OBJ = $(SRC:.o=.c)

%.o:%.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
		@make -sC $(LIBFT)
		@chmod 777 $(MINILIBX)/./configure
		@make -sC $(MINILIBX)
		$(CC) $(FLAGS) $(OBJ) -Lminilibx-linux $(EXTRAFLAGS) -o $(NAME)

clean: 
		${RM} ${OBJ_1} ${OBJ_2} ${NAME}
		@cd ${LIBFT} && ${MAKE} clean
		@cd $(MINILIBX) && &(MAKE) clean

fclean: clean
		${RM} ${NAME}
		@cd ${LIBFT} && ${MAKE} fclean
		@cd $(MINILIBX) && &(MAKE) fclean

re: fclean all