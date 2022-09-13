#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{

}

HumanB::~HumanB()
{
    
}

void HumanB::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_myWeapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &myWeapon)
{
    this->_myWeapon = &myWeapon;
}