#include <iostream>
#include <string>

class Zombie
{
    public :

    Zombie();

    void announce( void );
    void setName( std::string name );

    ~Zombie();
    
    private :

    std::string _name;
};  

Zombie* zombieHorde( int N, std::string name );