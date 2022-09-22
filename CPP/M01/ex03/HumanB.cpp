/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/14 13:28:29 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

}

HumanB::~HumanB()
{
    
}

void HumanB::attack() const
{
    if (this->_myWeapon->getType() == "")
        std::cout << this->_name << " can't attacks" << std::endl;
    else
       std::cout << this->_name << " attacks with their " << this->_myWeapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &myWeapon)
{
    this->_myWeapon = &myWeapon;
}