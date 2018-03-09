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

NAME = libftprintf.a

LIB = libft.a

SRC = ft_printf.c ft_convert.c ft_geters.c ft_flags_lenth.c \
	ft_maxgeters.c ft_setters.c ft_printers.c ft_print_inf.c

FLG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ cd ./libft && make
	@ ar rc $(NAME) $(OBJ) ./libft/*.o
	
%.o: %.c
	@ gcc $(FLG) -c -o $@ $<

clean:
	@ /bin/rm -rf $(OBJ)
	@ cd ./libft && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(OBJ)
	@ /bin/rm -f $(LIB)
	@ /bin/rm -f libft/$(LIB)


re: fclean all

.PHONY : all, re, clean, flcean
