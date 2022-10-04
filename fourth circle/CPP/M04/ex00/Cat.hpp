#ifndef CAT_HPP
#   define CAT_HPP

#   include "Animal.hpp"
#   include <iostream>

class Cat : public Animal {

    public:
        Cat();
        ~Cat();
        Cat(Cat const &cpy);
        Cat& operator=(Cat const &op);
        
        void makeSound() const;
};

#endif