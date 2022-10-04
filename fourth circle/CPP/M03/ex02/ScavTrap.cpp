/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/23 10:47:34 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    this->_name = name;
    this->_hit = 100;
    this->_energy = 50;
    this->_attack_damage = 20;
    std::cout << "ScavTrap Constructor: " << this->_name << " is created" << std::endl << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy){
    std::cout << "ScavTrap Copy" << std::endl;
    this->_name = copy.getName();
    this->_attack_damage = copy.getAttackDamage();
    this->_energy = copy.getEnergyPoints();
    this->_hit = copy.getHitPoints();
    std::cout << "Copy of "<<  this->_name << " is create\n" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &op){
    std::cout << "ScavTrap assignement operator =" << std::endl;
    std::cout << "Changement d'identite : " <<  this->getName();
    if (&op != this)
    {
        this->_name = op.getName();
        this->_attack_damage = op.getAttackDamage();
        this->_energy = op.getEnergyPoints();
        this->_hit = op.getHitPoints();
    }
    std::cout << " devient "<<  this->_name << "\n" << std::endl;
    return (*this);
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