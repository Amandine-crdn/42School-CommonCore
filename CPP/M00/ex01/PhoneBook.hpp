#ifndef PHONEBOOOK_HPP
# define PHONEBOOOK_HPP
#   include "Contact.hpp"
#   include <string>
#   include <stdlib.h>
#   include <iomanip>
#   include <iostream>

class PhoneBook {

public :

    PhoneBook();
    void add_contact();
    bool search();
    void print_index() const;
    ~PhoneBook();

private :

    void print_first();
    std::string replace(std::string key);
    std::string is_empty();
    int value_index(int i, int choice);
    Contact contact[8];
    int _max_contact;
};

#endif