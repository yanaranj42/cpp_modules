# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 20:39:21 by yanaranj          #+#    #+#              #
#    Updated: 2025/07/07 17:47:09 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RED = \e[1;91m
GREEN = \e[1;92m

SRC = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
		Intern.cpp
CC = c++ #-g
CFLAGS = -Wall -Werror -Wextra -std=c++98 #-fsanitize=address
RM = rm -f
OBJ = $(SRC:.cpp=.o)

HEADER = Makefile Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp \
		Intern.hpp

NAME = Actions

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)At least this beats coffee-making✅"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)objects had been removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Bye!🫰"

re: fclean all

.PHONY: all clean fclean re