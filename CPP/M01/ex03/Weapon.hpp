#ifndef WEAPON_HPP
#   define WEAPON_HPP

#   include <string>
#   include <iostream>

class Weapon{

    public :
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        std::string const & getType() const;
        void setType( std::string new_type );

    private :
        std::string _type;

};

#endif