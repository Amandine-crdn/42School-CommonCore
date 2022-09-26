#ifndef CAT_HPP
#   define CAT_HPP

#   include "Brain.hpp"
#   include "AAnimal.hpp"
#   include <iostream>

class Cat : public AAnimal {

    public:
        Cat();
        ~Cat();
        Cat(Cat const &cpy);
        Cat& operator=(Cat const &op);
        
        void makeSound() const;
        void setBrain( std::string idea );
        void getBrain() const;
        void setValue(int i);
        int  getValue() const;

    private:
        Brain *_brain;
        int    _value;
};

#endif