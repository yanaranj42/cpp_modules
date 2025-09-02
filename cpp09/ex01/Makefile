# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:39:21 by yanaranj          #+#    #+#              #
#    Updated: 2025/08/26 13:30:47 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RED = \e[1;91m
GREEN = \e[1;92m


SRC = main.cpp RPN.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
OBJ = $(SRC:.cpp=.o)

HEADER = Makefile RPN.hpp

NAME = RPN

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Reverse Polish Notation ✅"

%.o: %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling $<..."

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)objects had been removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Bye!🫰"

re: fclean all

.PHONY: all clean fclean re