/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/14 13:17:36 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#   define HUMAN_A_HPP

#   include <string>
#   include <iostream>
#   include "Weapon.hpp"

class HumanA{

     public :
        HumanA(std::string name, Weapon &myWeapon);
        ~HumanA();
        void attack() const;

    private :
        std::string _name;
        Weapon &_myWeapon;

};

#endif