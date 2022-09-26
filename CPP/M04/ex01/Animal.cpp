#include "Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
    std::cout << "Animal Constructor" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal Destructor" << std::endl;
}

Animal::Animal( Animal const &cpy ) {
    this->type = cpy.type; 
    std::cout << this->getType() << " with Animal Copy Constructor" << std::endl;
}

Animal& Animal::operator=( Animal const &op ) {
    std::cout << this->getType() << " becomes ";
    if (op.getType() != this->getType())
        this->setType(op.type);
    std::cout << this->getType() << " by Animal Surcharge d'Assignator" << std::endl;
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