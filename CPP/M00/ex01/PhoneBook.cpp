#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    u = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

void    PhoneBook::add_contact()
{
        std::string buff;
        std::string name;
        
        if (this->u == 8)
            this->u == 0;
        //cin.clear()
        // retour a la ligne a chaque msg
        std::cout << "first name : "; std::getline(std::cin, name); this->contact[this->u].first_name = name;
        std::cout << "last name : "; std::getline(std::cin, buff); this->contact[this->u].last_name = buff;
        std::cout << "nickname : "; std::getline(std::cin, buff); this->contact[this->u].nickname = buff;
        std::cout << "phone number : "; std::getline(std::cin, buff); this->contact[this->u].phone_number = buff;
        std::cout << "darkest secret : "; std::getline(std::cin, buff); this->contact[this->u].darkest_secret = buff;
        this->u++;
        std::cout << std::endl << name << " is added at your repertory\n" << std::endl;
}

std::string    ft_change(std::string str)
{
    if (str.size() > 10)
        {
            str.resize(9);
            str.push_back('.');
        }
    return (str);
}

void    PhoneBook::print_contact(void) // FORCER A RENTRER QLQ CHOSE
{
    int i = 0;
    int number;
    std::string str;
    std::string copy;

    
    std::cout << std::endl;
    std::cout << "|";
    str = "index"; std::cout << std::setw(10) << str.substr(0,10) << "| ";
    str = "first name"; std::cout << std::setw(10) << str.substr(0,10) << "| ";
    str = "last name"; std::cout << std::setw(10) << str.substr(0,10) << "| ";
    str = "nickname"; std::cout << std::setw(10) << str.substr(0,10) << "| " << std::endl;

    std::cout << "|----------------------------------------------|" << std::endl;
    while (i < this->u) 
    {
        std::cout << "|"; std::cout << std::setw(10) << i << "| ";
        copy = ft_change(this->contact[i].first_name); std::cout << std::setw(10) << copy.substr(0,10) << "| ";
        copy = ft_change(this->contact[i].last_name); std::cout << std::setw(10) << copy.substr(0,10) << "| ";
        copy = ft_change(this->contact[i].nickname); std::cout << std::setw(10) << copy.substr(0,10) << "| \n" << std::endl;
        i++;
    }
    if (this->u == 0)
    {
        std::cout << "You havent contact, please ADD" << std::endl;
        return ;
    }
    else
        std::cout << std::endl << "Tape the index of the contact you wanna see" << std::endl;
    std::cin >> number; std::cin.ignore();
    if  (std::cin.eof())
        return ;
    else if (number >= 0 || number < this->u) // autre que 0.1.2.34 a gerer
    {
        std::cout << "first name : " << this->contact[number].first_name << std::endl;
        std::cout << "last name : " << this->contact[number].last_name << std::endl;
        std::cout << "nickname : " << this->contact[number].nickname << std::endl;
        std::cout << "phone number : " << this->contact[number].phone_number << std::endl;
        std::cout << "darkest secret : " << this->contact[number].darkest_secret << std::endl;
    }

}
