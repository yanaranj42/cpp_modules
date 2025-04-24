SRC = Contact.cpp PhoneBook.cpp #main.cpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f
OBJ = $(SRC:.c=.o)


NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re