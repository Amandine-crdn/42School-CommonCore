
#ifndef WEAPON_HPP
#define WEAPON_HPP

//	INCLUDES
# include <iostream>

//	CLASS
class Weapon
{
    private:
        std::string	_type;
        
    public:
        Weapon(std::string type);
        ~Weapon();

        const std::string&	getType();
        void				setType(std::string type);	
};

#endif