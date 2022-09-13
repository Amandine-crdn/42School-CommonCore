#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name("no_name")
{
    this->_name = name;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;;
}

Zombie::~Zombie()
{
    std::cout << this->_name << ": is dead..." << std::endl;;
}
