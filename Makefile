# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 01:30:00 by junhyupa          #+#    #+#              #
#    Updated: 2022/12/30 19:43:06 by junhyupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

CC := cc
CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address

RM := rm -f

INCLUDE := ./pipex.h

LIBFT := ./libft/libft.a
LIBFT_DIR := ./libft/

SRC := pipex.c util.c excuter.c parser.c

SRCS := $(addprefix ./srcs/,$(SRC))

OBJS := $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I $(INCLUDE) -o $(NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR)

.PHONY : all clean fclean re
