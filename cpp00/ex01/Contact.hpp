#ifndef CONTACT_H
#define CONTACT_H
#include <string>

/* tenemos atributos privados que pertenecen a un contacto
De manera publica tenemos la funcion get y set para encapsular el input
en cada fiel del contacto. Y lo ponemos const para que a la hora de ser
llamado, este no se copie ni sea modificado.
Y ponemos constructor para inicializar los miembros de la clase al crear el obj
Y el destructor para liberar los recursos antes de eliminar el miembro de la clase 
*/
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