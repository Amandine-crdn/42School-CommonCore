/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/14 13:17:36 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::complain( std::string level_spe)
{
    int i = 0;

    std::string choice_level[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    
    for(i = 0; level_spe != choice_level[i] && i < 4; i++);
    
    std::cout << "i = " << i << std::endl;
    
    switch (i)
    {
        case 0: Harl::debug(); i++;
        case 1: Harl::info(); i++;
        case 2: Harl::warning(); i++;
        case 3: Harl::error(); i++; break;
        default:
        {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            std::cout << std::endl;
            break;
        }
    }
}

void Harl::debug( void )
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
    std::cout << std::endl;

}
void Harl::info( void )
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger ! If you did, I wouldnt be asking for more !" << std::endl;
    std::cout << std::endl;
}
void Harl::warning( void )
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "Think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month" << std::endl;
    std::cout << std::endl;
}
void Harl::error( void )
{
    std::cout << "[ERROR]" << std::endl;
    std::cout <<"This is unacceptable, I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}