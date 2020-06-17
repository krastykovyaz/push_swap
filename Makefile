# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/05 23:00:18 by lnoisome          #+#    #+#              #
#    Updated: 2020/06/06 11:29:33 by lnoisome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME = push_swap
C_NAME = checker

RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[0;0m"
CYAN = "\033[1;35m"

CC = gcc
FLAGS = -Wall -Werror -Wextra

CHECKER_DIR = ./checker_src/
CHECKER_HEADER = $(CHECKER_DIR)includes/
C_SRC = ch_main.c \
	ch_order.c \
	check_s.c \
	com_inspect.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_strlen.c \
	ft_strsplit.c \
	ft_strsub.c \
	get_next_line.c \
	new_line.c \
	push_func.c \
	pushtostack.c \
	read_seq.c \
	rever_rotat_func.c \
	rotate_func.c \
	swap_func.c
C_FILES = $(addprefix $(CHECKER_DIR), $(C_SRC))
C_OBJ = $(addprefix $(CHECKER_DIR), $(patsubst %.c, %.o, $(C_SRC)))
D_FILE_C = $(addprefix $(CHECKER_DIR), $(patsubst %.c, %.d, $(C_SRC)))

PUSH_SWAP_DIR = ./push_swap_src/
PUSH_SWAP_HEADER = $(PUSH_SWAP_DIR)includes/
P_SRC = check.c \
	errors.c \
	ft_atoi.c \
	is_integer.c \
	pass.c \
	qsort.c \
	unique.c \
	find_position.c \
	solve_2.c \
	solve_3.c \
	solve_4.c \
	solve_5.c \
	switcher.c \
	switcher2.c \
	switcher3.c \
	crud.c \
	init.c \
	memory.c \
	functions.c \
	main.c
	
P_FILES = $(addprefix $(PUSH_SWAP_DIR), $(P_SRC))
P_OBJ = $(addprefix $(PUSH_SWAP_DIR), $(patsubst %.c, %.o, $(P_SRC)))
D_FILE_P = $(addprefix $(PUSH_SWAP_DIR), $(patsubst %.c, %.d, $(P_SRC)))

.PHONY: all clean fclean re

all: $(PS_NAME) $(C_NAME)

$(PS_NAME): $(P_OBJ)
	@$(CC) $(P_OBJ) -I $(PUSH_SWAP_HEADER) -o $(PS_NAME)
	@echo $(GREEN)$(PS_NAME) -\> Build done!$(RESET)

$(PUSH_SWAP_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@$(CC) $(FLAGS) -I $(PUSH_SWAP_HEADER) -MD -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(C_NAME): $(C_OBJ)
	@$(CC) $(C_OBJ) -I $(CHECKER_HEADER) -o $(C_NAME)
	@echo $(GREEN)$(C_NAME) -\> Build done!$(RESET)

$(CHECKER_DIR)%.o: $(CHECKER_DIR)%.c
	@$(CC) $(FLAGS) -I $(CHECKER_HEADER) -MD -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

clean:
	@rm -rf $(P_OBJ) \& $(C_OBJ) \& $(D_FILE_P) \& $(D_FILE_C)
	@echo $(RED)Object files was deleted$(RESET)

fclean: clean
	@rm -rf $(PS_NAME) \& $(C_NAME)
	@echo $(RED)$(PS_NAME) \& $(C_NAME) was deleted$(RESET)

include $(wildcard $(D_FILE_P) \& $(D_FILE_C))

re: fclean all
