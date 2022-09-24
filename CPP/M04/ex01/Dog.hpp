#ifndef DOG_HPP
#   define DOG_HPP

#   include "Animal.hpp"
#   include "Brain.hpp"
#   include <iostream>

class Dog : public Animal {

    public:
        Dog();
        ~Dog();
        Dog(Dog const &cpy);
        Dog& operator=(Dog const &op);

        void makeSound() const;

    private:
        Brain *_brain;
};

#endif