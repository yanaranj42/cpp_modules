#include "PhoneBook.hpp"

int is_validNumber(std::string input)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (input[len])
		len++;
	while (i < len)
	{
		if (input[i] >= '0' && input[i] <= '9')
			i++;
		else
			return(0);
	}
    return (1);
}

PhoneBook::PhoneBook()
{
}      
PhoneBook::~PhoneBook()
{
}

void PhoneBook::welcome()const
{
	std::cout << "This is my PhoneBook" << std::endl;
	std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}
void	PhoneBook::add_contact(void)
{
	std::string str;

	str = "";
	this->index = 0;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "First Name: ";
		if (getline(std::cin, str) && str != "")
			this->contacts[index].set_firstname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Last Name: ";
		if (getline(std::cin, str) && str != "")
			this->contacts[index].set_lastname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Nickname: ";
		if (getline(std::cin, str) && str != "")
			this->contacts[index].set_nickname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Phone Number: ";
		if (getline(std::cin, str) && str != "")
		{
			if (is_validNumber(str))
				this->contacts[index].set_number(str);
			else
			{
				std::cout << "Introduce only digits\n";
				str = "";
			}
		}
 	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Darkest Secret: ";
		if (getline(std::cin, str) && str != "")
			this->contacts[index].set_darksecret(str);
	}
	std::cout << "Contact Added successfully" << std::endl;
	
	//this->index = (index + 1) % 8;
	//if (this->size < 8)
	//	this->size++;
}

