#ifndef CONTACT_H
#define CONTACT_H
#include <string>

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
        const std::string& get_firstname(void) const;
        const std::string& get_lastname(void) const;
        const std::string& get_nickname(void) const;
        const std::string& get_number(void) const;
        const std::string& get_darksecret(void) const;
        void    set_firstname(std::string firstname);
        void    set_lastname(std::string lastname);
        void    set_nickname(std::string nickname);
        void    set_number(std::string number);
        void    set_darksecret(std::string darksecret);
};
#endif