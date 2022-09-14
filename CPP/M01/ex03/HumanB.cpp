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