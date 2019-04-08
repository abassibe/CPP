# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2019/04/07 18:52:18 by dhadley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRCS =	main.cpp \
		CPUModule.cpp \
		DateModule.cpp \
		HostModule.cpp \
		OSModule.cpp \
		RAMModule.cpp \
		NetworkModule.cpp \
		ConsoleView.cpp \
		CPUActivityModule.cpp \
		RAMActivityModule.cpp \
		GraphicalView.cpp \

OBJS = $(SRCS:.cpp=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

DIR_OBJ = objs/

LIBS = -L ~/.brew/lib -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath ~/.brew/lib


all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS))
	@g++ -lncurses $(LIBS) $(FLAGS) $^ -o $(NAME)

$(DIR_OBJ)%.o: $(SRCPATH)%.cpp
	@mkdir -p objs
	@g++ $(FLAGS) -c $< -o $@ -I includes -I SFML/include

.PHONY: all clean fclean re

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@make
