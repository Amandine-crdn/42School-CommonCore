#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << this->getType() << " Constructor" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << this->getType() << " Destructor" << std::endl;
}

WrongCat::WrongCat( WrongCat &cpy ) : WrongAnimal() {
    this->type = cpy.type; 
    std::cout << this->getType() << " Copy Constructor" << std::endl;
}

WrongCat& WrongCat::operator=( WrongCat &op ) {
    std::cout << this->getType() << " becomes ";
    if (op.getType() != this->getType())
        this->setType(op.type);
    std::cout << this->getType() << " by Surcharge d'Assignator" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const{ 
    std::cout << "The " << this->getType() << " is Meowing" << std::endl;
}