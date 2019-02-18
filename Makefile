# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/11 14:04:06 by moboussa     #+#   ##    ##    #+#        #
#    Updated: 2019/02/05 19:23:21 by moboussa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

NAME = fdf

SRC = ft_main.c \
	ft_readfile.c \
	ft_parsing.c \
	ft_graph.c \
	ft_trace_line.c \
	ft_eventkey.c 

LIB = libft/libft.a

MLX = minilibx_macos/libmlx.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra


all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OBJ)
	make -C libft
	$(CC) -framework OpenGL -framework AppKit -I includes -o $@ $^ $(LIB) $(MLX) $(FLAGS)

$(LIB):
	make -C libft

$(MLX):
	make -C minilibx_macos

%.o: %.c
	 $(CC) -I includes -o $@ -c $< $(FLAGS)

clean:
	make -C libft clean
	make -C minilibx_macos clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX)
	rm -rf $(LIB)

re: fclean all