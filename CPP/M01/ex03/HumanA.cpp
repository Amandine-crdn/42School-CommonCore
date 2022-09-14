#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &myWeapon) : _name(name), _myWeapon(myWeapon)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack() const
{
    if (this->_myWeapon.getType() == "")
        std::cout << this->_name << " attacks with flower " << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_myWeapon.getType() << std::endl;
}
