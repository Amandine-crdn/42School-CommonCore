#include "Zombie.hpp"

 Zombie* newZombie( std::string name )
 {
    Zombie* brainz = new Zombie(name);
    return (brainz);
 }