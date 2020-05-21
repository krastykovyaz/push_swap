# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/20 14:41:46 by ccharmai          #+#    #+#              #
#    Updated: 2020/05/20 22:43:06 by lnoisome         ###   ########.fr        #
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

PUSH_SWAP_DIR = ./push_swap_src/
PUSH_SWAP_HEADER = $(PUSH_SWAP_DIR)includes/

PS_ROOT_SRC = functions.c \
	main.c
PS_ROOT_FILES = $(addprefix $(PUSH_SWAP_DIR), $(PS_ROOT_SRC))
PS_ROOT_OBJ = $(addprefix $(PUSH_SWAP_DIR), $(patsubst %.c, %.o, $(PS_ROOT_SRC)))

PS_LIBS_SRC = check.c \
	errors.c \
	ft_atoi.c \
	is_integer.c \
	pass.c \
	qsort.c \
	unique.c
PS_LIBS_DIR = libs/
PS_LIBS_FILES = $(addprefix $(PUSH_SWAP_DIR), $(addprefix $(PS_LIBS_DIR), $(PS_LIBS_SRC)))
PS_LIBS_OBJ = $(addprefix $(PUSH_SWAP_DIR), $(patsubst %.c, %.o, $(PS_LIBS_SRC)))

PS_SOLVE_SRC = find_position.c \
	solve_2.c \
	solve_3.c \
	solve_4.c \
	solve_5.c \
	switcher.c \
	switcher2.c \
	switcher3.c
PS_SOLVE_DIR = solve/
PS_SOLVE_FILES = $(addprefix $(PUSH_SWAP_DIR), $(addprefix $(PS_SOLVE_DIR), $(PS_SOLVE_SRC)))
PS_SOLVE_OBJ = $(addprefix $(PUSH_SWAP_DIR), $(patsubst %.c, %.o, $(PS_SOLVE_SRC)))

PS_STACK_SRC = crud.c \
	init.c \
	memory.c
PS_STACK_DIR = stack/
PS_STACK_FILES = $(addprefix $(PUSH_SWAP_DIR), $(addprefix $(PS_STACK_DIR), $(PS_STACK_SRC)))
PS_STACK_OBJ = $(addprefix $(PUSH_SWAP_DIR), $(patsubst %.c, %.o, $(PS_STACK_SRC)))

PS_FILES = $(PS_ROOT_FILES) $(PS_LIBS_FILES) $(PS_SOLVE_FILES) $(PS_STACK_FILES)
PS_OBJ = $(PS_ROOT_OBJ) $(PS_LIBS_OBJ) $(PS_SOLVE_OBJ) $(PS_STACK_OBJ)

OBJ = $(C_OBJ) $(PS_OBJ)

.PHONY: all clean fclean re

all: $(C_NAME) $(PS_NAME)

$(C_NAME): $(C_OBJ)
	@$(CC) $(C_OBJ) -I $(CHECKER_HEADER) -o $(C_NAME)
	@echo $(GREEN)$(C_NAME) -\> Build done!$(RESET)

$(CHECKER_DIR)%.o: $(CHECKER_DIR)%.c
	@$(CC) $(FLAGS) -I $(CHECKER_HEADER) -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(PS_NAME): $(PS_OBJ)
	@$(CC) $(PS_OBJ) -I $(PUSH_SWAP_HEADER) -o $(PS_NAME)
	@echo $(GREEN)$(PS_NAME) -\> Build done!$(RESET)

$(PUSH_SWAP_DIR)%.o: $(PUSH_SWAP_DIR)$(PS_LIBS_DIR)%.c
	@$(CC) $(FLAGS) -I $(PUSH_SWAP_HEADER) -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(PUSH_SWAP_DIR)%.o: $(PUSH_SWAP_DIR)$(PS_SOLVE_DIR)%.c
	@$(CC) $(FLAGS) -I $(PUSH_SWAP_HEADER) -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(PUSH_SWAP_DIR)%.o: $(PUSH_SWAP_DIR)$(PS_STACK_DIR)%.c
	@$(CC) $(FLAGS) -I $(PUSH_SWAP_HEADER) -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

$(PUSH_SWAP_DIR)%.o: $(PUSH_SWAP_DIR)%.c
	@$(CC) $(FLAGS) -I $(PUSH_SWAP_HEADER) -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

clean:
	@rm -rf $(OBJ)
	@echo $(RED)Object files was deleted$(RESET)

fclean: clean
	@rm -rf $(PS_NAME) $(C_NAME)
	@echo $(RED)$(PS_NAME) \& $(C_NAME) was deleted$(RESET)

deb:
	@echo $(PS_OBJ)

re: fclean all
