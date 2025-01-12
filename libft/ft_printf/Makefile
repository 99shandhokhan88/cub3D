# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 22:26:18 by flo-dolc          #+#    #+#              #
#    Updated: 2024/12/23 00:20:08 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
BLUE		=	\033[0;34m
RESET		=	\033[0m

SRCS		=	ft_printf.c \
				hex_utils.c \
				numbers_utils.c \
				pointer_utils.c \
				strings_utils.c

OBJS_DIR	=	obj/

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

NAME		=	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	@rm -f

all:			$(NAME)

$(OBJS_DIR):
				@echo "$(YELLOW)Creating object directory...$(RESET)"
				@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o:	%.c | $(OBJS_DIR)
				@echo "$(BLUE)Compiling $<...$(RESET)"
				@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS_DIR) $(OBJS)
				@echo "$(GREEN)Linking objects and creating $(NAME)...$(RESET)"
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

clean:
				@echo "$(RED)Cleaning object files...$(RESET)"
				$(RM) $(OBJS)
				$(RM) -r $(OBJS_DIR)

fclean:			clean
				@echo "$(RED)Removing executable...$(RESET)"
				$(RM) $(NAME)

re:				fclean all

norm:
				@echo "$(BLUE)Running norminette...$(RESET)"
				@norminette $(SRCS)

.PHONY:			all bonus clean fclean re norm
