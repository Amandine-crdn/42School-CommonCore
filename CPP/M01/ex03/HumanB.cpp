#include "HumanB.hpp"

HumanB::HumanB(std::string name)//	constructor
{
	this->_name = name;
	this->isArmed = false;

	std::cout << this->_name << " has joined the battle." << std::endl;
	return ;
}

HumanB::~HumanB()//	destructor
{
	std::cout << this->_name << " has lost the battle, but not the war. He'll come back!" << std::endl;
	return ;
}

void	HumanB::attack()
{
	if (this->isArmed)
		std::cout << this->_name << " attacks the enemy with a " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " is unarmed. He attacks with his famous IRON FIST" << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& type)
{
	srand(time(0));
	this->isArmed = rand() %2;
	this->_weapon = &type;
}