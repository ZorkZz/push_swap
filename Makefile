# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 15:19:24 by astachni@st       #+#    #+#              #
#    Updated: 2023/02/04 13:01:39 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS_DIR = objs/

SRCS = main.c srcs/simple_sort.c srcs/double_sort.c srcs/utils.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

LIBS = libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -g3 -fsanitize=address

RM = rm -f

HEADERS = headers/push_swap.h

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	make bonus -C libs/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@norminette main.c srcs/*.c

clean:
	make clean -C libs/libft
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C libs/libft

all: $(NAME)

re:	fclean
	$(NAME) all

.PHONY: all clean fclean re