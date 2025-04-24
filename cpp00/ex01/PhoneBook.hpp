#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	size;
		int	index;
	public:
        PhoneBook();
        ~PhoneBook();
		PhoneBook() : size(0), index(0) {};
		//int get_size(void) const;
		void add_contact(std::string data[5]);
		void seach_contact(int i) const;
		void display(void)const;
        void welcome(void)const;
};

#endif