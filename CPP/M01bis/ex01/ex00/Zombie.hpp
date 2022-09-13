#ifndef ZOMBIE_HPP
#   define ZOMBIE_HPP

#   include <string>
#   include <iomanip>
#   include <iostream>
#   include <stdlib.h>

class Zombie
{

    public:
        Zombie();
        ~Zombie();
        void		setName(std::string name);
        void		announce() const;

    private:
        std::string	_name;

};

Zombie*		zombieHorde( int N, std::string name );

#endif