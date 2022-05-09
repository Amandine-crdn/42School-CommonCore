#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <sstream>
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
    //private: addcontact
    public :    
    
    PhoneBook(void);
    Contact contact[8];
    int u;
    void add_contact(void);
    void print_contact(void);
    
    ~PhoneBook(void);
};

#endif
