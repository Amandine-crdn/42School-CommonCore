#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    /*std::cout << "1/" << std::endl;
    const Animal* j = new Dog();
    std::cout << "2/" << std::endl;
    const Animal* i = new Cat();
    std::cout << "3/" << std::endl;
    delete j;//should not create a leak
    std::cout << "4/" << std::endl;
    delete i;*/

    /*
         //MES TESTS 
    
    int total = 5;
    Animal *tab[total];

    std::cout << "----- Constructions -------" << std::endl;
    for (int u = 0; u < total; u++)
    {
        if (u % 2 == 0)
            tab[u] = new Dog();
        else
            tab[u] = new Cat();
    }

    std::cout << "----- Destructions -------" << std::endl;
    while (total - 1 >= 0)
    {
        delete tab[total - 1];
        total --;
    }*/


    
    /*    std::cout << "\n----- copies profondes -------" << std::endl;
    
    std::cout << "\n***** COUCOU INFO *****\n";
    Dog coucou;
    coucou.setBrain("J'aime me balader");
    coucou.setBrain("J'adore manger mes croquettes");
    coucou.getBrain(); // affiche le contenu du tableau de _brain dans Dog
    std::cout << "\n***** COPY INFO *****\n";
    Dog copy(coucou); // copy profonde
    copy.getBrain();
    std::cout << copy.getType() << std::endl;
    std::cout << "\n***** EGAL INFO ******\n";
    Dog egal;
    egal = coucou;
    egal.getBrain();
    std::cout << "\n----- Destructions -------" << std::endl;*/
    return 0;
}