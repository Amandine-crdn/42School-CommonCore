/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 10:46:13 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#   define SCAVTRAP_HPP

    #include <iostream>
    #include "ClapTrap.hpp"
class ScavTrap : public ClapTrap {

    public :
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &copy);
        ScavTrap& operator=(ScavTrap const &op);
        ~ScavTrap();

        void attack(const std::string& target);
        void guardGuate();
};

#endif