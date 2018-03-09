# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 17:34:30 by tvertohr          #+#    #+#              #
#    Updated: 2017/11/09 15:28:28 by tvertohr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_memalloc.c ft_memdel.c ft_bzero.c \
	ft_strnew.c ft_strlen.c ft_strindexof.c ft_strdup.c \
	ft_atoi.c ft_strcount.c \
	ft_putwchar.c ft_putwstr.c ft_wstrlen.c \
	ft_putlenstr.c ft_putnchar.c ft_putchar.c \
	ft_isdigit.c ft_isupper.c ft_power.c ft_itoa_base.c ft_uitoa_base.c \
	ft_putstr.c ft_strcpy.c ft_memset.c ft_memcpy.c ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strncpy.c \
	ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c \
	ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_swap.c \
	ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_list_last.c ft_list_size.c \
	ft_itoa.c ft_whitespace.c ft_list_reverse.c \
	ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \

OBJ = $(SRC:.c=.o)

$(NAME): libft.h $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
