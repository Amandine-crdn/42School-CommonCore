/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 10:50:18 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    this->_name = name;
    std::cout << "ScavTrap Constructor with name : " << this->_name << std::endl << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &op){
    std::cout << "ScavTrap Operator=" << std::endl;
    if (&op != this)
        *this = op; //tester si ca marche
    return (*this);
}

ScavTrap::ScavTrap(ScavTrap const &copy){
    std::cout << "ScavTrap Copy" << std::endl;
    *this = copy;
}

void ScavTrap::attack(const std::string& target){
    if (this->_energy > 0 && this->_hit > 0)
    {
        this->_energy--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage" << std::endl;
    }
    else if (this->_hit <= 0)
        std::cout << "I'm sorry.. " << this->_name << " can't attack cause he's die..\n" << std::endl;
    else
        std::cout << "I'm sorry.. " << this->_name << " can't attack cause he'd not enought point" << std::endl;
}

void ScavTrap::guardGuate(){
    std::cout << "ScavTrap " << this->_name << " est entré en mode Gate keeper.\n"<< std::endl;
}