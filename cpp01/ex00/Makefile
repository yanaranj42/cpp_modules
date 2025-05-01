# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 16:15:07 by yanaranj          #+#    #+#              #
#    Updated: 2025/05/01 16:43:33 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RED = \e[1;91m
GREEN = \e[1;92m
OTHER = \033[38;5;154m

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf
OBJ = $(SRC:.cpp=.o)

HEADER = Zombie.hpp Makefile

NAME = braiiiinz

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) BraiiiiiiinnnzzzZ Done✅"
clean:
	@$(RM) $(OBJ)
	@echo "$(OTHER)objects removed"
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)program removed"

re: fclean all

.PHONY: all clean fclean re
