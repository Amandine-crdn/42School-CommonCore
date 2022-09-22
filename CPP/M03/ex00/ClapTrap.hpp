#ifndef CLAPTRAP_HPP
#   define CLAPTRAP_HPP

    #include <iostream>

class ClapTrap{

    public :
        ClapTrap();
        ClapTrap(std::string name); //a voir si _name ou name..
        ClapTrap(ClapTrap const &copy);
        ClapTrap& operator=(ClapTrap const &op);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);


    private :
        std::string _name;
        int _hit;
        int _energy;
        int _attack_damage;


};

#endif