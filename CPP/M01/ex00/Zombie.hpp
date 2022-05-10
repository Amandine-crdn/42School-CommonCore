#include <iostream>

class Zombie
{
    public :

    Zombie();

    void announce( void );
    Zombie(std::string name);

    ~Zombie();
    
    private :

    std::string _name;
};  

Zombie* newZombie( std::string name );
void randomChump( std::string name );