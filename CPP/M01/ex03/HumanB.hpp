
#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"


class HumanB
{
    private:
        Weapon*		_weapon;
        std::string	_name;
        bool		isArmed;

    public:
        HumanB(std::string name);
        ~HumanB();

        void	attack();
        void	setWeapon(Weapon& type);
};

#endif