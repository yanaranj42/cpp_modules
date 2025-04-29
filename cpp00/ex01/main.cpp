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
        else if (input == "PRINT")
            phonebook.print();
        //else if (input == "SEACH")
        //    phonebook.search_contact(input);//le pasamos un str
        else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command\n" << std::endl;
    }
    return (0);
}