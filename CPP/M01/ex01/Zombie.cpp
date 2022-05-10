#include "Zombie.hpp"

Zombie::Zombie()
{
     std::cout << "creator of : " << "Georges" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << _name << " destructor" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}
