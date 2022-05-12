#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::complain( std::string level )
{
    if (level == "DEBUG")
        Harl::debug();
    else if (level == "INFO")
        Harl::info();
    else if (level == "WARNING")
        Harl::warning();
    else if (level == "ERROR")
        Harl::error();
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl::warning( void )
{
     std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; 
}
