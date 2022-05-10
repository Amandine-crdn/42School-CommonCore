#include "Zombie.hpp"

int main()
{
    Zombie* john = newZombie("John");
    randomChump("Louis");
    john->announce();
    delete john;
    return (0);
}
