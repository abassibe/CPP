# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2019/04/05 17:47:05 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wathever

SRCS =	whatever.cpp \

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

DIR_OBJ = objs/

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS))
	@g++ $(FLAGS) $^ -o $(NAME)

$(DIR_OBJ)%.o: %.cpp
	@mkdir -p objs
	@g++ $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	@rm -rf objs

fclean: clean
	@rm -rf  $(NAME)

re: fclean
	@make
