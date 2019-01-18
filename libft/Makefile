# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: moboussa <moboussa@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 12:55:54 by moboussa     #+#   ##    ##    #+#        #
#    Updated: 2019/01/15 19:33:48 by moboussa    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

FLAG = -c -Wall -Wextra -Werror
SRC = ft_strlen.c \
		ft_strsub.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_itoa.c \
		ft_isprint.c \
		ft_memset.c \
		ft_strcat.c \
		ft_bzero.c \
		ft_atoi.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_strlcat.c \
		ft_lstadd.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstdel.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strsplit.c \
		get_next_line.c \
		ft_freetab_char.c \
		ft_freetab_int.c \
		ft_realloc.c
OBJ = ft_strlen.o \
		ft_strsub.o \
		ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_itoa.o \
		ft_isprint.o \
		ft_memset.o \
		ft_strcat.o \
		ft_bzero.o \
		ft_atoi.o \
		ft_memalloc.o \
		ft_memccpy.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memdel.o \
		ft_memmove.o \
		ft_putchar_fd.o \
		ft_putchar.o \
		ft_putendl_fd.o \
		ft_putendl.o \
		ft_putnbr_fd.o \
		ft_putnbr.o \
		ft_putstr.o \
		ft_putstr_fd.o \
		ft_strchr.o \
		ft_strclr.o \
		ft_strcmp.o \
		ft_strcpy.o \
		ft_strdel.o \
		ft_strdup.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strjoin.o \
		ft_strncat.o \
		ft_strncmp.o \
		ft_strncpy.o \
		ft_strnew.o \
		ft_strnstr.o \
		ft_strrchr.o \
		ft_strstr.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_strtrim.o \
		ft_strlcat.o \
		ft_lstadd.o \
		ft_lstdelone.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_lstnew.o \
		ft_lstdel.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strsplit.o \
		get_next_line.o \
		ft_freetab_char.o \
		ft_freetab_int.o \
		ft_realloc.o
NAME = libft.a
HEADER = libft.h

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all