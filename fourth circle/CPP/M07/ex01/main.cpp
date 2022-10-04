#include "Iter.hpp"

int main( void )
{
    int tab[5] = { 0, 1, 2, 3, 4 };
    std::cout << "Tableau d'int" << std::endl;
    iter(tab, 5, &display);

    double tab_d[5] = { 0.5, 1.2, 2.2, 3.7, 4.4 };
    std::cout << "\nTableau d'int" << std::endl;
    iter(tab_d, 5, &display);

    std::cout << "\nTableau de string" << std::endl;
    std::string str[3] = { "salut", "ca va", "oui"};
    iter(str, 3, &display);

    std::cout << "\nTableau de char" << std::endl;
    char c[2] = { 'a', 'z'};
    iter(c, 2, &display);

    std::cout << "\nTableau de char" << std::endl;
    bool choice[2] = {true, false};
    iter(choice, 2, &display);

    return 0;
}