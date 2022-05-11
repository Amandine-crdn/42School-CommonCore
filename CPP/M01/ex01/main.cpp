#include "Zombie.hpp"

int main()
{   
    int i = 0;
    int N;
    std::string name;
    
    std::cout << "Combien de zombies souhaites-tu creer ?" << std::endl;
    std::cin >> N;
    std::cout << "Comment veux-tu qu'ils s'appellent ?" << std::endl;
    std::cin >> name;

    Zombie* horde = zombieHorde(N, name);
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete [] horde;
    return (0);
}
