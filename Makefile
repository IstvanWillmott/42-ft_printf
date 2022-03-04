# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 13:08:54 by iwillmot          #+#    #+#              #
#    Updated: 2022/03/04 15:53:20 by iwillmot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = src/ft_printf.c \
	   src/ft_modifiers.c \
	   src/ft_putstr.c \
	   src/ft_putnum.c \
	   src/ft_itoa.c \
	   src/ft_hexadecimal.c \
	   src/ft_putnum_unsigned.c \
	   src/ft_putptr.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

INCLUDES = -I./includes/

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) -c $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
