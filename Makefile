NAME = cub3D

RAYCASTING_DIR = src/raycasting
PARSER_DIR = src/parser
OBJ_DIR = obj
INC_DIR = include
MLX_DIR = minilibx

SRC = $(wildcard $(RAYCASTING_DIR)/*.c) \
      $(wildcard $(PARSER_DIR)/*.c) \
      main.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I $(INC_DIR) -I $(MLX_DIR)
LFLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

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

all: $(OBJ_DIR) $(MLX_DIR)/libmlx.a $(NAME)
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

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)⚡ $(RESET)$(notdir $<)\n"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@printf "$(PURPLE)>> Opening Portal...$(RESET)\n"

clean:
	@printf "$(RED)>> Exorcising Demons...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean > /dev/null 2>&1

fclean: clean
	@printf "$(RED)>> Sealing Hell Gates...$(RESET)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
