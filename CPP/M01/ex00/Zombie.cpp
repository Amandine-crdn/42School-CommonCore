#include "Zombie.hpp"

Zombie::Zombie()
{
    Zombie::randomChump(_name);
}

Zombie::Zombie(std::string name) : _name(name)
{
    return ;
}


Zombie::~Zombie()
{
    
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

