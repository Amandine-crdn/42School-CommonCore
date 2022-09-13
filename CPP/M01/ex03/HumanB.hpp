#ifndef HUMAN_B_HPP
#   define HUMAN_B_HPP

#   include <string>
#   include <iostream>
#   include "Weapon.hpp"

class HumanB{

    public :
        HumanB(std::string name);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon &_myWeapon);

    private :
        Weapon *_myWeapon;
        std::string _name;

};

#endif