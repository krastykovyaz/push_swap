# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/22 15:58:40 by lnoisome          #+#    #+#              #
#    Updated: 2020/04/25 22:20:58 by lnoisome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	afterdot.c \
		convert.c \
		convert_hex.c \
		convertf.c \
		convertf2.c \
		decimal_pregular_space.c \
		flag.c \
		float_minus.c \
		float_plus.c \
		float_space.c \
		float_zero.c \
		free_list.c \
		ft_atoi.c \
		ft_float.c \
		ft_itoa.c \
		ft_itoa2.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnchar.c \
		ft_putnstr.c \
		ft_putstr.c \
		ft_round.c \
		ft_strlen.c \
		if_digit.c \
		percent.c \
		precision.c \
		search_type.c \
		size.c \
		type_decimal_minus.c \
		type_decimal_plus.c \
		type_decimal_regular.c \
		type_decimal_size.c \
		type_decimal_space.c \
		type_decimal_zero.c \
		type_float_priority.c \
		type_float_size.c \
		type_hex_minus.c \
		type_hex_regular.c \
		type_hex_size.c \
		type_octal_minus.c \
		type_octal_regular.c \
		type_octal_size.c \
		type_octal_zero.c \
		type_priority_octal.c \
		type_str.c \
		width.c \
		type_address.c \
		type_perc.c \
		errors.c \
		ft_equal.c \
		colors.c \
		append.c \
		ft_strdup.c 

OBJ =	afterdot.o \
		convert.o \
		convert_hex.o \
		convertf.o \
		convertf2.o \
		decimal_pregular_space.o \
		flag.o \
		float_minus.o \
		float_plus.o \
		float_space.o \
		float_zero.o \
		free_list.o \
		ft_atoi.o \
		ft_float.o \
		ft_itoa.o \
		ft_itoa2.o \
		ft_printf.o \
		ft_putchar.o \
		ft_putnbr.o \
		ft_putnchar.o \
		ft_putnstr.o \
		ft_putstr.o \
		ft_round.o \
		ft_strlen.o \
		if_digit.o \
		percent.o \
		precision.o \
		search_type.o \
		size.o \
		type_decimal_minus.o \
		type_decimal_plus.o \
		type_decimal_regular.o \
		type_decimal_size.o \
		type_decimal_space.o \
		type_decimal_zero.o \
		type_float_priority.o \
		type_float_size.o \
		type_hex_minus.o \
		type_hex_regular.o \
		type_hex_size.o \
		type_octal_minus.o \
		type_octal_regular.o \
		type_octal_size.o \
		type_octal_zero.o \
		type_priority_octal.o \
		type_str.o \
		width.o \
		type_address.o \
		type_perc.o \
		errors.o \
		ft_equal.o \
		colors.o \
		append.o \
		ft_strdup.o 

HEADER = includes/

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) -I $(HEADER)
	@ar -rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
