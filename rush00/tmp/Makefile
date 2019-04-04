NAME = ft_retro

SRCS =	main.cpp \
		Enemies.cpp \
		Player.cpp \
		Rand.cpp \
		Square.cpp \
		Weapon.cpp \
		Win.cpp \
		Shot.cpp

OBJS = $(SRCS:.cpp=.o)

SRCPATH = srcs/

FLAGS = -Wall -Wextra -Werror

DIR_OBJ = objs/

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS))
	@g++ -lncurses $(FLAGS) $^ -o $(NAME)

$(DIR_OBJ)%.o: $(SRCPATH)%.cpp
	@mkdir -p objs
	@g++ $(FLAGS) -c $< -o $@ -I ./includes

.PHONY: all clean fclean re

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@make
