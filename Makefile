# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 13:08:54 by iwillmot          #+#    #+#              #
#    Updated: 2022/02/28 16:20:18 by iwillmot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/ft_printf.c \
	   src/ft_modifiers.c \
	   src/ft_putstr.c \
	   src/ft_putnum.c \
	   src/ft_itoa.c \
	   src/ft_hexadecimal.c \
	   src/ft_putnum_unsigned \
	   src/ft_putptr

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./includes/

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
