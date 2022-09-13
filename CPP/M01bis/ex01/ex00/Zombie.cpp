#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A Zombie is create" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "A Zombie is die" << std::endl;
	return ;
}

void		Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}

void	Zombie::announce() const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
