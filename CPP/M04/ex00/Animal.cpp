#include "Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
    std::cout << this->getType() << " Constructor" << std::endl;
}

Animal::~Animal() {
    std::cout << this->getType() << " Destructor" << std::endl;
}

Animal::Animal( Animal &cpy ) {
    this->type = cpy.type; 
    std::cout << this->getType() << " Copy Constructor" << std::endl;
}

Animal& Animal::operator=( Animal &op ) {
    std::cout << this->getType() << " becomes ";
    if (op.getType() != this->getType())
        this->setType(op.type);
    std::cout << this->getType() << " by Surcharge d'Assignator" << std::endl;
    return (*this);
}

std::string Animal::getType() const{
    return (this->type);
}

void Animal::setType(std::string change) {
    this->type = change;
}

void Animal::makeSound() const{ 
    std::cout << " is Grouuuuuaaa" << std::endl;
}