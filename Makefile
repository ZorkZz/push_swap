# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 15:19:24 by astachni@st       #+#    #+#              #
#    Updated: 2023/03/25 15:00:39 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

OBJS_DIR = objs/

SRCS = main.c srcs/simple_sort.c srcs/double_sort.c srcs/utils.c srcs/sort.c srcs/parsing.c srcs/max_pos.c srcs/quick_sort.c srcs/parsing_error.c srcs/utils0.c srcs/radix.c srcs/error.c srcs/ft_atol.c

# LIBS_PATH = libs/libft/ft_isalpha.c libs/libft/ft_isdigit.c libs/libft/ft_isalnum.c libs/libft/ft_isascii.c libs/libft/ft_isprint.c libs/libft/ft_strlen.c libs/libft/ft_memset.c libs/libft/ft_bzero.c libs/libft/ft_memcpy.c libs/libft/ft_memmove.c libs/libft/ft_strlcpy.c libs/libft/ft_strlcat.c libs/libft/ft_toupper.c libs/libft/ft_tolower.c libs/libft/ft_strchr.c libs/libft/ft_strrchr.c libs/libft/ft_strncmp.c libs/libft/ft_memchr.c libs/libft/ft_memcmp.c libs/libft/ft_strnstr.c libs/libft/ft_atoi.c libs/libft/ft_calloc.c libs/libft/ft_strdup.c libs/libft/ft_substr.c libs/libft/ft_strjoin.c libs/libft/ft_strtrim.c libs/libft/ft_split.c libs/libft/ft_itoa.c libs/libft/ft_strmapi.c libs/libft/ft_striteri.c libs/libft/ft_putchar_fd.c  libs/libft/ft_putstr_fd.c libs/libft/ft_putendl_fd.c libs/libft/ft_putnbr_fd.c libs/libft/ft_strjoin.c libs/libft/ft_printf/src/ft_itoa_u.c libs/libft/ft_printf/src/itoa_hex_point.c libs/libft/ft_printf/src/itoa_hex.c libs/libft/ft_printf/src/print_func.c libs/libft/ft_printf/ft_printf.c libs/libft/get_next_line/get_next_line.c libs/libft/get_next_line/get_next_line_utils.c libs/libft/Makefile

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