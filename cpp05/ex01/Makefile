# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:39:21 by yanaranj          #+#    #+#              #
#    Updated: 2025/07/01 12:29:16 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RED = \e[1;91m
GREEN = \e[1;92m

SRC = Bureaucrat.cpp main.cpp Form.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
OBJ = $(SRC:.cpp=.o)

HEADER = Makefile Bureaucrat.hpp Form.hpp

NAME = Form

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Form up, maggots!✅"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)objects had been removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Bye!🫰"

re: fclean all

.PHONY: all clean fclean re