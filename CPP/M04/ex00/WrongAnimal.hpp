#ifndef WRONGANIMAL_HPP
#   define WRONGANIMAL_HPP

#   include <iostream>

class WrongAnimal {

    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal( WrongAnimal &cpy );
        WrongAnimal& operator=( WrongAnimal &op );
        
        void setType( std::string change );
        std::string getType() const;
        void makeSound() const;
    
    protected:
        std::string type;
};

#endif