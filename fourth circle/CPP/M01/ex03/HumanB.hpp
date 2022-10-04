/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/14 13:17:36 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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