#include "ScavTrap.hpp"

int main()
{
    ClapTrap player1("Rockie");
    ScavTrap player2("Dragon"); //copy de class, declarer avec les 2 constructeurs

    player1.attack("Dragon");
    player2.takeDamage(5);
    player2.beRepaired(10);
    player2.attack("Rockie");
    player1.takeDamage(10);
    player1.beRepaired(5);
    player2.attack("Rockie");
    player1.takeDamage(10);
    player2.guardGuate(); // impossible de l'appeler avec player1 (ClapTrap)

    return (0);
}