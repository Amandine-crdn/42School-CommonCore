#ifndef CAT_HPP
#   define CAT_HPP

#   include "Brain.hpp"
#   include "Animal.hpp"
#   include <iostream>

class Cat : public Animal {

    public:
        Cat();
        ~Cat();
        Cat(Cat const &cpy);
        virtual Cat& operator=(Cat const &op);
        
        void makeSound() const;
    
    private:
        Brain *_brain;
};

#endif