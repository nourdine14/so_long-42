# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 23:42:34 by nakebli           #+#    #+#              #
#    Updated: 2023/02/21 12:58:47 by nakebli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =    so_long_bonus

SRCS =	main_bonus.c \
		check/check_map_bonus.c \
		check/path_valid_bonus.c \
		check/path_valid_utils_bonus.c \
		drawing/draw_map_bonus.c \
		hooks/hook_utils_bonus.c \
		hooks/hook_bonus.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = solong_bonus.h

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