#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::complain( std::string level )
{
    void (Harl::*choice_function[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string choice_level[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    for (int i = 0; i < 4; i++)
	{
		if (level == choice_level[i])
			(this->*choice_function[i])();
	}
}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}
void Harl::info( void )
{
     std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger ! If you did, I wouldnt be asking for more !" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}