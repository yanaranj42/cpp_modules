#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>

class Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string number;
        std::string darksecret;
    public:
        Contact();
        ~Contact();
		void  newContact(void);
        const std::string& get_firstname(void) const;
        const std::string& get_lastname(void) const;
        const std::string& get_nickname(void) const;
        const std::string& get_number(void) const;
        const std::string& get_darksecret(void) const;
		std::string set_input(std::string info);
		std::string set_number(std::string info);
};
#endif