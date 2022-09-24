#ifndef ANIMAL_HPP
#   define ANIMAL_HPP

#   include <iostream>

class Animal {

    public:
        Animal();
        ~Animal();
        Animal(Animal &cpy);
        Animal& operator=(Animal &op);

        void setType(std::string change);
        std::string getType() const;
        void makeSound() const;

    protected :
        std::string type;
};

#endif