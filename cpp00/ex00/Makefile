# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 12:28:29 by yanaranj          #+#    #+#              #
#    Updated: 2025/05/02 14:00:08 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = megaphone.cpp
OBJS = ${SRC:.cpp=.o}
RM = rm -f
CC  = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

all : $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CPPFLAGS) $(OBJS) -o ${NAME}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

PHONY: all clean fclean re