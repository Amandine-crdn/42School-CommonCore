#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) :
	_weapon(type),
	_name(name)
{
	std::cout << this->_name << " has joined the battle.";
	std::cout << " He carries a " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " has lost the battle, but not the war. He'll come back!" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks the enemy with a " << this->_weapon.getType() << std::endl;
}