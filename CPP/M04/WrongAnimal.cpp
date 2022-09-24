#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << this->getType() << " Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << this->getType() << " Destructor" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal &cpy ) {
    this->type = cpy.type; 
    std::cout << this->getType() << " Copy Constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal &op ) {
    std::cout << this->getType() << " becomes ";
    if (op.getType() != this->getType())
        this->setType(op.type);
    std::cout << this->getType() << " by Surcharge d'Assignator" << std::endl;
    return (*this);
}

std::string WrongAnimal::getType() const{
    return (this->type);
}

void WrongAnimal::setType(std::string change) {
    this->type = change;
}

void WrongAnimal::makeSound() const{ 
    std::cout << " is Grouuuuuaaa" << std::endl;
}