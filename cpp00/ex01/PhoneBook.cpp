#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->size = 0;
	this->index = 0;
}      
PhoneBook::~PhoneBook()
{
}

void PhoneBook::welcome()const
{
	std::cout << std::endl;
	std::cout << "--------Yajaira's PhoneBook-------" << std::endl;
    std::cout << "ADD\t: To add a new contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: To quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::add_contact(void)
{
	std::string str;

	if (this->index >= 8)
	{
		std::cout << "You are going to overwrite a contact " << this->contacts[this->index % 8].get_firstname() << std::endl;
	}
	if (size < 8)
		size++;
	this->contacts[index % 8].newContact();
	
	std::cout << "\n✅Contact Added successfully✅" << std::endl;
	this->index++;
}

std::string	fix_size(std::string str, int max)
{
	std::string new_str;
	int			i;

	if (str.size() > max)
	{
		new_str = str.substr(0, max);
		new_str += ".";
	}
	else
	{
		i = 0;
		while (i++ < 10 - str.length())
			std::cout << " ";
		new_str = str;
	}
	return (new_str);
}

void	PhoneBook::display_contact(int i) const
{
	if (!contacts[i].get_firstname().size())
	{
		std::cerr << "This Index does not exist ❌" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "You selected Index: " << i << std::endl;
	std::cout << std::endl;
	std::cout << "First Name:\t" << contacts[i].get_firstname() << std::endl;
	std::cout << "Last Name:\t" << contacts[i].get_lastname() << std::endl;
	std::cout << "Nickname:\t" << contacts[i].get_nickname() << std::endl;
	std::cout << "Phone Num:\t" << contacts[i].get_number() << std::endl;
	std::cout << "Dark Secret:\t" << contacts[i].get_darksecret() << std::endl;
}

void	PhoneBook::search_contact(void) const
{
	std::string input;
	int	i;

	i = 0;
	if (size == 0)
	{
		std::cerr << " Yaja's PhoneBook is empty 👀" << std::endl;
		return ;
	}
	else
	{
		std::cout << " ____________________________________________ " << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		while (i < size)
		{
			std::cout << "|" << fix_size(std::to_string(i), 9);
			std::cout << "|" << fix_size(contacts[i].get_firstname(), 9);
			std::cout << "|" << fix_size(contacts[i].get_lastname(), 9);
			std::cout << "|" << fix_size(contacts[i].get_nickname(), 9) << "|" << std::endl;
			i++;
		}
		std::cout << " ___________________________________________ " << std::endl;
	}
	while (1)
	{
		std::cout << "Select an Index: ";
		getline(std::cin, input);
		if (!std::cin)
			exit(2);
		if (input != "")
		{
			if (input.size() == 1 && input[0] >= '0' && input[0] <= '7')
			{
				PhoneBook::display_contact(input[0] - '0');
				break;
			}
			else
				std::cout << "Index out of range ❌" << std::endl;
		}
		else if (input == "")
			std::cout << "Try again 🔃" << std::endl;
	}
}
