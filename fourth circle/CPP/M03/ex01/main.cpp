/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/23 10:37:38 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap player1("Rockie"); std::cout << player1 << std::endl;
    ScavTrap player2("Dragon"); std::cout << player2 << std::endl;

    player1.attack("Dragon"); std::cout << player1 << std::endl;
    player2.takeDamage(99); std::cout << player2 << std::endl;
    player2.beRepaired(12); std::cout << player2 << std::endl;
    player2.guardGuate();
    player2.attack("Rockie");
    player1.takeDamage(20); std::cout << player1 << std::endl;
    return (0);
}