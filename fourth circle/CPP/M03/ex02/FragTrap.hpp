/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 10:55:03 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#   define FRAGTRAP_HPP

    #include <iostream>
    #include "ScavTrap.hpp"

class FragTrap : public ClapTrap {

    public :
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &copy);
        FragTrap& operator=(FragTrap const &op);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif