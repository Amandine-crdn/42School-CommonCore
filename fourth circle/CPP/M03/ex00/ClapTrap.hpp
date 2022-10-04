/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/23 08:16:35 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#   define CLAPTRAP_HPP

    #include <iostream>

class ClapTrap{

    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ClapTrap& operator=(ClapTrap const &op);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        //getters
        std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
        
    private :
        std::string _name;
        int _hit;
        int _energy;
        unsigned int _attack_damage;
};

std::ostream &operator<<(std::ostream &os, const ClapTrap &claptrap);

#endif