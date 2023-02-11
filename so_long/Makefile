# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 23:42:34 by nakebli           #+#    #+#              #
#    Updated: 2023/02/11 14:35:05 by nakebli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =    so_long

SRCS =	main.c \
		../check/check_map.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

HEADER = ../check/check.h

RM = rm -rf

all: $(NAME) $(OBJS) $(HEADER)

%.o: %.c $(HEADER)
	@cc -c $(CFLAGS)  $<  -o $@

$(NAME): $(OBJS) 
	@make -C ../libft
	@cc -o $(NAME) $(OBJS) ../libft/libft.a 

clean:
	@$(RM) $(OBJS)
	@make clean -C ../libft

fclean:clean
	@$(RM) $(NAME)
	@make fclean -C ../libft

re: fclean all
