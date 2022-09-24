#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

/*TEST POUR DES WRONG*/
    #include "WrongCat.hpp"
    #include "WrongAnimal.hpp"

int main()
{
    /*  TESTS PRINCIPAUX*/

    std::cout << "\n1/\n";
    const Animal* meta = new Animal();
    std::cout << "\n2/\n";
    const Animal* j = new Dog();
    std::cout << "\n3/\n";
    const Animal* i = new Cat();
    std::cout << "\n4/\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "\n5/\n";
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    /*  TEST POUR LES ANIMAUX ET LES CHIENS*/

    /*Animal zebre;
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
    std::cout << strange.getType(); strange.makeSound();*/



    /*TEST POUR DES WRONG*/

    /*const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the Animal sound!
    meta->makeSound();*/

    return (0);
}