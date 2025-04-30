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
		int	size;
	public:
        PhoneBook();
        ~PhoneBook();
		void add_contact(void);
		void search_contact(void) const;
		void display_contact(int i) const;
        void welcome(void)const;
};

#endif