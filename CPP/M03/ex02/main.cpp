/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 10:59:03 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    ClapTrap player1("Rockie");
    ScavTrap player2("Dragon"); //copy de class, declarer avec les 2 constructeurs
    FragTrap player3("Robot");

    player1.attack("Dragon");
    player2.takeDamage(5);
    player2.beRepaired(10);
    player2.attack("Rockie");
    player1.takeDamage(10);
    player1.beRepaired(5);
    player2.attack("Rockie");
    player1.takeDamage(10);
    player2.guardGuate();
    player3.highFivesGuys(); // impossible de l'appeler avec player1 (ClapTrap) ou player 2 (ScavTrap)
    return (0);
}