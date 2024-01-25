# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzibari <hzibari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 14:33:04 by hzibari           #+#    #+#              #
#    Updated: 2024/01/24 11:43:48 by hzibari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/libft.a

NAME	=	push_swap

SRCS	=	push_swap.c \
			check_and_create.c \
			utils.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \
			eazy_sorters.c \
			big_sorter.c \
			targets_and_cost.c \
			position_and_index.c \
			move.c

OFILES	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	-rm -f
CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) ${OFILES}
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		make clean -C libft
		$(RM) $(OFILES)
	
fclean: clean
		make fclean -C libft
		$(RM) $(NAME) $(OFILES)

re: fclean all

.PHONY: all clean fclean re