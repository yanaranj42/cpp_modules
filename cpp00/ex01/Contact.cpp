#include "Contact.hpp"

Contact::Contact()
{
}
Contact::~Contact()
{
}
int is_validNumber(std::string input)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!input[0])
		return (0);
	while (input[len])
		len++;
	if (len > 9)
	{
		std::cout << "Number cannot contain more than 9 digits" << std::endl;
		return (0);
	}
	while (i < len)
	{
		if (input[i] >= '0' && input[i] <= '9')
			i++;
		else
		{
			std::cout << "Introduce only digits\n";
			return(0);
		}
	}
    return (1);
}

std::string Contact::set_number(std::string info)
{
	std::string input;

	while (1)
	{
		std::cout << info;
		getline(std::cin, input);
		if (!std::cin)
		{
			std::cout << "Bye, Bye!!🫰" << std::endl;
			exit(2);
		}
		if (input.empty())
			std::cout << "Phonebook expects a " << info << std::endl;
		if (is_validNumber(input))
			return (input);
	}
	return (NULL);
}
std::string Contact::set_input(std::string info)
{
	std::string input;

	while (1)
	{
		std::cout << info;
		getline(std::cin, input);
		if (!std::cin)
		{
			std::cout << "Bye, Bye!!🫰" << std::endl;
			exit(2);
		}
		if (input == "")
			std::cout << "PhoneBook expects a " << info << std::endl;
		else
			return (input);
	}
	return (NULL);
}
void Contact::newContact()
{
	this->firstname = Contact::set_input(std::string("First Name: "));
	this->lastname = Contact::set_input(std::string("Last Name: "));
	this->nickname = Contact::set_input(std::string("Nickname: "));
	this->number = Contact::set_number(std::string("Phone Number: "));
	this->darksecret = Contact::set_input(std::string("Darkest Secret: "));
}

const std::string& Contact::get_firstname(void) const
{
    return (this->firstname);
}
const std::string& Contact::get_lastname(void) const
{
    return (this->lastname);
}
const std::string& Contact::get_nickname(void) const
{
    return (this->nickname);
}
const std::string& Contact::get_number(void) const
{
    return (this->number);
}
const std::string& Contact::get_darksecret(void) const
{
    return (this->darksecret);
}
