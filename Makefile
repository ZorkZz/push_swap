# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 15:19:24 by astachni@st       #+#    #+#              #
#    Updated: 2023/02/07 16:33:13 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS_DIR = objs/

SRCS = main.c srcs/simple_sort.c srcs/double_sort.c srcs/utils.c srcs/sort.c srcs/parsing.c srcs/max_pos.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

LIBS = libs/libft/libft.a libs/ft_printf/libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADERS = headers/push_swap.h

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	make bonus -C libs/libft
	make -C libs/ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@norminette main.c srcs/*.c

clean:
	make clean -C libs/libft
	make clean -C libs/ft_printf
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C libs/ft_printf
	make fclean -C libs/libft
	rm push_swap

all: $(NAME)

re:	fclean all

.PHONY: all clean fclean re