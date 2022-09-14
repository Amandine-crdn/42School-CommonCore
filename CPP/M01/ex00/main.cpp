#include "Zombie.hpp"

int main()
{
    Zombie* zombie;

//sur la stack

    randomChump("Nicolas");

// sur la heap

    zombie = newZombie("Thierry");
    zombie->announce();
    delete zombie;
    return (0);
}