# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:39:21 by yanaranj          #+#    #+#              #
#    Updated: 2025/06/03 16:25:36 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RED = \e[1;91m
GREEN = \e[1;92m

SRC = Test.cpp main.cpp DerivedA.cpp Inherit.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))
#DEPS = $(addprefix $(OBJDIR), $(SRC:.cpp=.d))
HEADER = Makefile Test.hpp DerivedA.hpp Inherit.hpp

NAME = test

$(OBJDIR)%.o: %.cpp Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling... $(patsubst $(DIR_BUILD)%,%,$@)"

all: dir $(NAME)

dir:
	@mkdir -p $(OBJDIR)

#-include $(DEPS)
$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Having fun ✅"

clean:
	@$(RM) $(OBJDIR)
	@echo "$(RED)objects had been removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Bye!🫰"

re: fclean all

.PHONY: all dir clean fclean re
