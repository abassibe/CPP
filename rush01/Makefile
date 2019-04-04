# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2019/04/04 09:33:42 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRCS =	main.cpp \

OBJS = $(SRCS:.cpp=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

DIR_OBJ = objs/

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS))
	@g++ $(FLAGS) $^ -o $(NAME)

$(DIR_OBJ)%.o: $(SRCPATH)%.cpp
	@mkdir -p objs
	@g++ $(FLAGS) -c $< -o $@ -I includes

.PHONY: all clean fclean re

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@make
