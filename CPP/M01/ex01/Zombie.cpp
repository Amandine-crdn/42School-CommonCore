#include "Zombie.hpp"

Zombie::Zombie()
{
     std::cout << "Creation of zombie" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " : Destruction of this zombie if the array was not dynamic" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}
