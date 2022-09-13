#include "Zombie.hpp"

int main()
{
    std::string str;
    Zombie* zombie;

//sur la stack

    randomChump("Nicolas");

// sur la heap

    zombie = newZombie("Thierry");
    zombie->announce();
    delete(zombie);
    return (0);
}