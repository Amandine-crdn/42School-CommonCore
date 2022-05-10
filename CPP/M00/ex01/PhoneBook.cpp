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


std::string    ft_print_error(std::string error_msg, std::string field, std::string keyword)
{
    while (field.empty())
    {
        std::cout << "You must write the " << keyword  << std::endl;
        std::cout << error_msg; std::getline(std::cin, field);
    }
    return (field);
}

void    PhoneBook::add_contact()
{
        std::string buff;
        std::string name;
        
        if (this->u == 8)
            this->u == 0;
        std::cout << "first name : "; std::getline(std::cin, name); 
        this->contact[this->u].first_name = ft_print_error("Please tape the first name : ", name, "first name");

        std::cout << "last name : "; std::getline(std::cin, buff);
        this->contact[this->u].last_name =ft_print_error("Please tape the last name : ", buff, "last name");

        std::cout << "nickname : "; std::getline(std::cin, buff);
        this->contact[this->u].nickname = ft_print_error("Please tape the nickname : ", buff, "nickname");
        
        std::cout << "phone number : "; std::getline(std::cin, buff); 
        this->contact[this->u].phone_number = ft_print_error("Please tape the phone number : ", buff, "phone number");

        std::cout << "darkest secret : "; std::getline(std::cin, buff);
        this->contact[this->u].darkest_secret = ft_print_error("Please tape the darkest secret : ", buff, "darkest secret");
        
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

void    PhoneBook::print_contact(void)
{
    int i = 0;
    unsigned int number;
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
        std::cout << "Error : you havent contact, please ADD" << std::endl;
        return ;
    }
    else
        std::cout << std::endl << "Tape the index of the contact you wanna see" << std::endl;
    std::cin >> number; 
    std::cin.ignore();
    if (std::cin.fail())
        std::cout << "Error : this repertory needs an int" << std::endl;
    else if (std::cin.eof())
         return ;
    else
    {
        if (number < this->u)
        {
            std::cout << "first name : " << this->contact[number].first_name << std::endl;
            std::cout << "last name : " << this->contact[number].last_name << std::endl;
            std::cout << "nickname : " << this->contact[number].nickname << std::endl;
            std::cout << "phone number : " << this->contact[number].phone_number << std::endl;
            std::cout << "darkest secret : " << this->contact[number].darkest_secret << std::endl;
        }
        else
            std::cout << "Error : " << number << " isn't exists in this repertory" << std::endl;
    }
}
