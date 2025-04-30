#include "PhoneBook.hpp"

int main()
{
    PhoneBook   phonebook;
    std::string input;

    while (1)
    {
        phonebook.welcome();
        std::getline(std::cin, input);
        if (input == "ADD")
            phonebook.add_contact();
        else if (input == "SEARCH")
            phonebook.search_contact();
        else if (input == "EXIT" || std::cin.eof())
		{
			std::cout << "Bye, Bye!!🫰" << std::endl;
			break;
		}
		else
			std::cerr << "Invalid command\n" << std::endl;
    }
    return (0);
}