# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 16:15:07 by yanaranj          #+#    #+#              #
#    Updated: 2025/05/07 19:49:07 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RED = \e[1;91m
GREEN = \e[1;92m
OTHER = \033[38;5;154m

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
#CFLAGS += -fsanitize=address -g
RM = rm -rf
OBJ = $(SRC:.cpp=.o)

HEADER = HumanA.hpp HumanB.hpp Weapon.hpp Makefile

NAME = violence

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Unnecessary Violence ✅"
clean:
	@$(RM) $(OBJ)
	@echo "$(OTHER)objects removed"
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)no more violence"

re: fclean all

.PHONY: all clean fclean re
