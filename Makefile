# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 15:19:24 by astachni@st       #+#    #+#              #
#    Updated: 2023/03/25 15:05:47 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS_DIR = objs/

SRCS = main.c srcs/simple_sort.c srcs/double_sort.c srcs/utils.c srcs/sort.c srcs/parsing.c srcs/max_pos.c srcs/quick_sort.c srcs/parsing_error.c srcs/utils0.c srcs/radix.c srcs/error.c srcs/ft_atol.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

LIBS = libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADERS = headers/push_swap.h

all: $(NAME)

$(LIBS):	FORCE
	$(MAKE) -C libs/libft all

FORCE:

$(OBJS_DIR)%.o: %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBS) $(OBJS) $(HEADERS) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@norminette

clean:
	make clean -C libs/libft
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C libs/libft
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re