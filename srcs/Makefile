# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 23:42:34 by nakebli           #+#    #+#              #
#    Updated: 2023/02/18 18:16:32 by nakebli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =    so_long

SRCS =	main.c \
		check/check_map.c \
		check/path_valid.c \
		drawing/draw_map.c \
		hooks/hook.c \
		hooks/hook_utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = solong.h

RM = rm -rf

all: $(NAME) $(OBJS) $(HEADER)
	@printf "\033[0;32mDONE ✅"

%.o: %.c $(HEADER)
	@cc -c $(CFLAGS) $<  -o $@
	@printf "\033[0;32m{compiling : %-30s .....} \r" ${notdir $@} 

$(NAME): $(OBJS) $(HEADER)
	make -C ../libft
	cc $(MLXFLAGS) -o $(NAME) $(OBJS) ../libft/libft.a 

clean:
	$(RM) $(OBJS)
	make clean -C ../libft
	@printf "\033[0;32mDONE ✅"

fclean:clean
	$(RM) $(NAME)
	make fclean -C ../libft

re: fclean all

.SILENT : $(NAME) clean fclean re

.PHONY : all clean fclean re