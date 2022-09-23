/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/23 10:38:20 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_name = name;
    this->_hit = 100;
    this->_energy = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap Constructor: " << this->_name << " is created" << std::endl << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &op){
    std::cout << "ScavTrap Operator=" << std::endl;
    if (&op != this)
    {
        this->_name = _name;
        this->_hit = 100;
        this->_energy = 50;
        this->_attack_damage = 20;
    }
    return (*this);
}

ScavTrap::ScavTrap(ScavTrap const &copy){
    std::cout << "ScavTrap Copy" << std::endl;
    *this = copy;
}

void ScavTrap::attack(const std::string& target){
    if (this->_hit <= 0 || this->_energy <= 0)
       std::cout << "I'm sorry.. " << this->_name << " ScavTrap can't attack"<< std::endl;
    else
    {
        this->_energy--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage" << std::endl;
    }
}

void ScavTrap::guardGuate(){
    std::cout << "ScavTrap " << this->_name << " est entré en mode Gate keeper.\n"<< std::endl;
}