/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 14:50:37 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    this->_name = ("no_name");
    this->_hit = 10;
    this->_energy = 10;
    this->_attack_damage = 0;
    std::cout << "ClapTrap Constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
    this->_name = name;
    this->_hit = 10;
    this->_energy = 10;
    this->_attack_damage = 0;
    std::cout << "ClapTrap Constructor with name : " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy){
    std::cout << "ClapTrap Copy" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &op)
{
    std::cout << "ClapTrap operator=" << std::endl;
    if (&op != this)
        *this = op;
    return (*this);
}
ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (this->_energy > 0 && this->_hit > 0)
    {
        this->_energy--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage" << std::endl;
    }
    else if (this->_hit <= 0)
        std::cout << "I'm sorry.. " << this->_name << " can't attack cause he's die..\n" << std::endl;
    else
        std::cout << "I'm sorry.. " << this->_name << " can't attack cause he'd not enought point" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
    if (amount > 4294967295)
        std::cout << "failed to give damage" << std::endl;
    if (this->_hit <= 0)
        std::cout << this->_name << " die..\n" << std::endl;
    else
    {
        std::cout << "Take " << amount << " points of damages\n" << std::endl;
        this->_hit -= amount;
    }
}
void ClapTrap::beRepaired(unsigned int amount){
    if (amount > 4294967295)
        std::cout << "failed to be repaired" << std::endl;
    else if (this->_energy < 0)
        std::cout << "I'm sorry.. " << this->_name << " can't be repaired cause he'd not enought point\n" << std::endl;
    else if (this->_hit)
        std::cout << "I'm sorry.. " << this->_name << " can't be repaired cause he die\n" << std::endl;
    else
    {
        this->_energy--;
        this->_hit += amount;
    }
}
