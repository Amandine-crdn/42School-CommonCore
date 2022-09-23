/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/23 10:43:29 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap Constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) {
    this->_name = name;
    this->_hit = 100;
    this->_energy = 100;
    this->_attack_damage = 30;
    std::cout << "FragTrap Constructor : " << this->_name << " is created" << std::endl << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &op){
    std::cout << "FragTrap Operator=" << std::endl;
    if (&op != this)
    {
        this->_name = _name;
        this->_hit = 100;
        this->_energy = 100;
        this->_attack_damage = 30;
    }
    return (*this);
}

FragTrap::FragTrap(FragTrap const &copy){
    std::cout << "FragTrap Copy" << std::endl;
    *this = copy;
}

void FragTrap::highFivesGuys(void){
    std::cout << "Do you wanna make a hight five ? No reponse please thx u"<< std::endl;
}