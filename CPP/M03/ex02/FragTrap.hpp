#ifndef FRAGTRAP_HPP
#   define FRAGTRAP_HPP

    #include <iostream>
    #include "ScavTrap.hpp"

class FragTrap : public ClapTrap {

    public :
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &copy);
        FragTrap& operator=(FragTrap const &op);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif