#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal zebre;
    std::cout << zebre.getType(); zebre.makeSound();
    
    Animal tamanoir;
    tamanoir = zebre;
    std::cout << tamanoir.getType(); tamanoir.makeSound();
    

    Dog whippet;
    std::cout << whippet.getType(); whippet.makeSound();

    Dog greyhound(whippet);
    std::cout << greyhound.getType(); greyhound.makeSound();

    //Dog iggy = tamanoir; ne marche pas car un chien ne peut pas devenir un animal
    Animal coucou(tamanoir);

    Animal strange;
    strange = greyhound; // un Animal peut devenir un chien
    std::cout << strange.getType(); strange.makeSound();
    return (0);
}