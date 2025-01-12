# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 19:58:07 by flo-dolc          #+#    #+#              #
#    Updated: 2024/12/23 00:20:21 by flo-dolc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
BLUE		=	\033[0;34m
RESET		=	\033[0m

SRCS		=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c

OBJS_DIR	=	obj/

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

NAME		=	libft.a

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
				@make --no-print-directory -C ./ft_printf
				@cp ./ft_printf/libftprintf.a $(NAME)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

clean:
				@echo "$(RED)Cleaning object files...$(RESET)"
				$(RM) $(OBJS)
				$(RM) -r $(OBJS_DIR)
				@make --no-print-directory -C ./ft_printf clean

fclean:			clean
				@echo "$(RED)Removing executable...$(RESET)"
				$(RM) $(NAME)
				@make --no-print-directory -C ./ft_printf fclean

re:				fclean all

norm:
				@echo "$(BLUE)Running norminette...$(RESET)"
				@norminette $(SRCS)
				@make --no-print-directory -C ./ft_printf norm

.PHONY:			all bonus clean fclean re norm
