#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    public :

    Contact(void);
   
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    
    ~Contact(void);
    
};

#endif