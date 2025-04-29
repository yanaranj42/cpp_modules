#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	index;
		//int	size;
	public:
        PhoneBook();
        ~PhoneBook();
		//int get_size(void) const;
		void add_contact(void);
		void print(void);
		//void search_contact(std::string input) const;
		//void display(void)const;
        void welcome(void)const;
};

#endif