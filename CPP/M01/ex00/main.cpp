#include "Zombie.hpp"




int main()
{
    Zombie zombie;
    Zombie* jim = newZombie("John");
    jim->announce();
    zombie.announce();
    delete jim;
    return (0);
}