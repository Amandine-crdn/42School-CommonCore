#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;
    return 0;
    std::cout << "----- mes tests ------" << std::endl;;
    Animal *tab[4];

    tab[0] = new Dog();
    tab[1] = new Dog();
    tab[2] = new Cat();
    tab[3] = new Cat();

    delete tab[0];
    delete tab[1];
    delete tab[2];
    delete tab[3];
   

    return 0;
}