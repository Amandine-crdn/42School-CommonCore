#ifndef ZOMBIE_HPP
#   define ZOMBIE_HPP

#   define ERROR_INPUT -1 

#   include <string>
#   include <iomanip>
#   include <iostream>
#   include <stdlib.h>

class Zombie {

public :

    Zombie( std::string name );
    ~Zombie();

    void announce( void );

private:

    std::string _name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif