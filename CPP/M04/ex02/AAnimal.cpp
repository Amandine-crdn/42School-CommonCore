#include "AAnimal.hpp"

AAnimal::AAnimal() {
    this->type = "AAnimal";
    std::cout << "AAnimal Constructor" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal Destructor" << std::endl;
}

AAnimal::AAnimal( AAnimal const &cpy ) {
    this->type = cpy.type; 
    std::cout << this->getType() << " with AAnimal Copy Constructor" << std::endl;
}

AAnimal& AAnimal::operator=( AAnimal const &op ) {
    std::cout << this->getType() << " becomes ";
    if (op.getType() != this->getType())
        this->setType(op.type);
    std::cout << this->getType() << " by AAnimal Surcharge d'Assignator" << std::endl;
    return (*this);
}

std::string AAnimal::getType() const{
    return (this->type);
}

void AAnimal::setType(std::string change) {
    this->type = change;
}

void AAnimal::makeSound() const{ 
    std::cout << " is Grouuuuuaaa" << std::endl;
}