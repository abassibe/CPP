# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2019/03/31 17:29:51 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRCS =	main.cpp \
		BodyScreen.cpp \
		InfosScreen.cpp \
		WeaponScreen.cpp \
		WaveScreen.cpp \
		Weapon.cpp \
		Player.cpp \
		Enemies.cpp \
		Shot.cpp \

OBJS = $(SRCS:.cpp=.o)

SRCPATH = srcs/

FLAGS = -Wall -Wextra -Werror

DIR_OBJ = objs/

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS))
	@g++ -lncurses $(FLAGS) $^ -o $(NAME)

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
