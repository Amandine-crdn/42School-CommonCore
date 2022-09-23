/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/23 10:39:06 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
ClapTrap::ClapTrap(){
    std::cout << "ClapTrap Constructor Default" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :  _name(name), _hit(10), _energy(10), _attack_damage(0){
    std::cout << "ClapTrap Constructor Called : data initialized" << std::endl;
    std::cout << this->_name << " is create\n" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy){
    std::cout << "ClapTrap Constructor Copy" << std::endl;
    this->_name = copy.getName();
    this->_attack_damage = copy.getAttackDamage();
    this->_energy = copy.getEnergyPoints();
    this->_hit = copy.getHitPoints();
    std::cout << "Copy of "<<  this->_name << " is create\n" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &op)
{
    std::cout << "ClapTrap assignement operator =" << std::endl;
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

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (this->_hit <= 0 || this->_energy <= 0)
       std::cout << "I'm sorry.. " << this->_name << " can't attack"<< std::endl;
    else
    {
        this->_energy--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "Take " << amount << " points of damages\n" << std::endl;
    if (amount > (unsigned int)this->_hit || this->_hit == 0)
    {
        this->_hit = 0;
        std::cout << this->_name << " die..\n" << std::endl;
    }
    else
        this->_hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_hit <= 0 || this->_energy <= 0)
        std::cout << "I'm sorry.. " << this->_name << " can't be repaired\n" << std::endl;
    else
    {
        this->_energy--;
        this->_hit += amount;
    }
}

///////// en plus

std::ostream &operator<<(std::ostream &os, const ClapTrap &claptrap)
{
        os << claptrap.getName() << " : nom" << std::endl;
        os << claptrap.getEnergyPoints() << " : energie point" << std::endl;
        os << claptrap.getHitPoints() << " : point de vie" << std::endl;
        return (os);
}

//getters
std::string ClapTrap::getName() const
{
	return (this->_name);
}
unsigned int ClapTrap::getHitPoints() const
{
	return (this->_hit);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_energy);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (this->_attack_damage);
}
