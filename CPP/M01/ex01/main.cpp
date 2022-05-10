#include "Zombie.hpp"

int main()
{   
    int i = 0;

    Zombie* horde = zombieHorde(42, "Georges");
    horde->announce();

    while (i < 42)
    {
        horde[i].announce();
        i++;
    }
    delete [] horde;
    return (0);
}
