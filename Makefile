# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 20:01:57 by vzashev           #+#    #+#              #
#    Updated: 2025/01/21 01:43:53 by vzashev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS_DIR = srcs

PARSER_DIR = $(SRCS_DIR)/parser

RAYCASTING_DIR = $(SRCS_DIR)/raycasting

OBJS_DIR = objs

INC_DIR = incs

MLX_DIR = minilibx

LIBFT_DIR = libft

RAYCASTING_SRC = $(wildcard $(RAYCASTING_DIR)/*.c)

PARSER_SRC = $(wildcard $(PARSER_DIR)/*.c)

MAIN_SRC = $(SRCS_DIR)/main.c

SRC = $(RAYCASTING_SRC) $(PARSER_SRC) $(MAIN_SRC)

OBJ = $(SRC:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -gdwarf-2 -O3

IFLAGS = -I $(INC_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR)

LFLAGS = -L $(MLX_DIR) -lmlx -L $(LIBFT_DIR) -lft -lXext -lX11 -lm -lbsd

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

define DOOM_BANNER
	@printf "$(RED)"
	@echo "                    ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄  ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄▄         "
	@echo "                   ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌        "
	@echo "                   ▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█▌▐░█▀▀▀▀▀▀▀▀▀         "
	@echo "                   ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌                   "
	@echo "                   ▐░▌          ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█▌▐░▌                   "
	@echo "                   ▐░▌          ▐░▌       ▐░▌▐░░░░░░░░░░▌▐░▌                   "
	@echo "                   ▐░▌          ▐░▌       ▐░▌▐░█▀▀▀▀▀▀▀█▌▐░▌                   "
	@echo "                   ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌                   "
	@echo "                   ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█▌▐░█▄▄▄▄▄▄▄▄▄         "
	@echo "                   ▐░░░░░░░░░░░▌▐░░░░░░░░░░▌▐░░░░░░░░░░▌ ▐░░░░░░░░░░░▌        "
	@echo "                    ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀   ▀▀▀▀▀▀▀▀▀▀▀         "
	@echo "                              INSPIRED BY DOOM (1994)                            "
	@printf "$(RESET)"
endef

all: $(OBJS_DIR) $(MLX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a $(NAME)
	@printf "$(GREEN)▀▄▀▄▀▄ WELCOME TO HELL ▄▀▄▀▄▀$(RESET)\n"

$(NAME): $(OBJ)
	$(DOOM_BANNER)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@printf "$(GREEN)[HELL GATES OPENED]$(RESET)\n"

$(MLX_DIR)/libmlx.a:
	@printf "$(CYAN)>> Loading Graphics Engine...$(RESET)\n"
	@printf "$(RED)"
	@for i in 1 2 3 4 5; do \
		echo "     ▄▄▄▄▄ █▄▄▄▄"; \
		echo "    █      █▄▄▄▄█"; \
		echo "     ▀▀▀▀▀ █    "; \
		printf "\033[3A"; sleep 0.1; \
		echo "    ▄▄▄▄▄  █ ▄▄▄"; \
		echo "   █      █▄▄▄▄█"; \
		echo "    ▀▀▀▀▀ █    "; \
		printf "\033[3A"; sleep 0.1; \
	done
	@printf "\033[3B$(RESET)"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

$(LIBFT_DIR)/libft.a:
	@printf "$(CYAN)>> Building Libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)⚡ $(RESET)$(notdir $<)\n"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)/parser
	@mkdir -p $(OBJS_DIR)/raycasting
	@printf "$(PURPLE)>> Opening Portal...$(RESET)\n"

clean:
	@printf "$(RED)>> Exorcising Demons...$(RESET)\n"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@printf "$(RED)>> Sealing Hell Gates...$(RESET)\n"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

test: all
	./$(NAME) map.cub

sub_test: all
	./$(NAME) maps/good/subject_map.cub

.PHONY: all clean fclean re test sub_test

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes