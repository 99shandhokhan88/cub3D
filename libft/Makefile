# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 21:36:49 by flo-dolc          #+#    #+#              #
#    Updated: 2025/01/21 01:53:11 by vzashev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS		=	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isdigit.c \
				ft_memset.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_substr.c \
				get_next_line.c \
				lists.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Werror -Wextra -Wall -g -gdwarf-2

all : $(NAME)
$(NAME) :
	cc -c $(FLAGS) -I ./ $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)
	
re : fclean all
