#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

//getter
std::string Contact::getFirstname() const
{
    return(_firstname);
}
std::string Contact::getLastname() const
{
     return(_lastname);
}
std::string Contact::getNickname() const
{
     return(_nickname);
}
std::string Contact::getPhone() const
{
     return(_phone);
}
std::string Contact::getSecret() const
{
     return(_secret);
}

//setter
void Contact::setFirstname(std::string firstname)
{
    _firstname = firstname;
}
void Contact::setLastname(std::string lastname)
{
    _lastname = lastname;
}
void Contact::setNickname(std::string nickname)
{
    _nickname = nickname;
}
void Contact::setPhone(std::string phone)
{  
    _phone = phone;
}
void Contact::setSecret(std::string secret)
{
    _secret = secret;
}
