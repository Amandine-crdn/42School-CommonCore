/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan   <acerdan@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acerdan           #+#    #+#             */
/*   Updated: 2022/09/22 10:13:38 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap player1;
    ClapTrap player2("Dragon"); //copy de class, declarer avec les 2 constructeurs

    player1.attack("Dragon"); //rockie energie 9
    player2.takeDamage(5);
    player2.beRepaired(10); //dragon energie 8 
    player2.attack("Rockie");
    player1.takeDamage(10); //rockie hit 0
    player1.beRepaired(5); //rockie energie 8 hit 5
    player2.attack("Rockie"); //dragon energie 7 
    player1.takeDamage(10); //rockie hit -5
    //try to repare himself
    player1.beRepaired(5); //rockie hit 0
    //rockie die but he wake up a last time and try to attack his ennemy
    player1.attack("Dragon");
    player2.attack("Rockie"); //dragon energie 7 
    player2.attack("Rockie"); //dragon energie 6 
    player2.attack("Rockie"); //dragon energie 5 
    player2.attack("Rockie"); //dragon energie 4 
    player2.attack("Rockie"); //dragon energie 3 
    player2.attack("Rockie"); //dragon energie 2 
    player2.attack("Rockie"); //dragon energie 1
    player2.attack("Rockie"); //dragon energie 0  
    //the dragon continues until exhaustion

    return (0);
}