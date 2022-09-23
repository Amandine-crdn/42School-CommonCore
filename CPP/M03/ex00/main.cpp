/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/23 10:21:18 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap player1("Rockie"); std::cout << player1 << std::endl;
    ClapTrap player2("Dragon"); std::cout << player2 << std::endl;
    //ClapTrap player3(player2); //tester constructeur par copie
    //player2 = player1; //tester operator de surcharge
    player1.attack("Dragon"); std::cout << player1 << std::endl;
    player2.takeDamage(99); std::cout << player2 << std::endl;
    player2.beRepaired(12);  std::cout << player2 << std::endl;
             
    return (0);
}