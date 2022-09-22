/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 10:13:38 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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