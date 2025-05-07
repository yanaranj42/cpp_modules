# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 16:15:07 by yanaranj          #+#    #+#              #
#    Updated: 2025/05/06 13:01:31 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RED = \e[1;91m
GREEN = \e[1;92m
OTHER = \033[38;5;154m

SRC = main.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf
OBJ = $(SRC:.cpp=.o)

HEADER = Makefile

NAME = hiBrain

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Hi this is brain✅"
clean:
	@$(RM) $(OBJ)
	@echo "$(OTHER)objects removed"
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)bye this is brain"

re: fclean all

.PHONY: all clean fclean re
