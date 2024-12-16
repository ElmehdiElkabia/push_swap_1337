# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelkabia <eelkabia@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 22:03:13 by eelkabia          #+#    #+#              #
#    Updated: 2024/12/16 22:06:35 by eelkabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
src = push_swap.c push_swap_utils.c reverse_rotate_operation.c rotate_operation.c swap_operation.c push_operation.c
obj = $(src:.c=.o)

all: $(NAME)

$(NAME): $(obj)
	$(CC) $(CFLAGS) -o $(NAME) $(obj)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all