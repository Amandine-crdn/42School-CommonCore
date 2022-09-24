#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << this->getType() << " Constructor" << std::endl;
}

Cat::~Cat() {
    std::cout << this->getType() << " Destructor" << std::endl;
    delete _brain;
}

Cat::Cat( Cat const &cpy ) : Animal() {
    this->type = cpy.type; 
    std::cout << this->getType() << " Copy Constructor" << std::endl;
}

Cat& Cat::operator=( Cat const &op ) {
   std::cout << this->getType() << " becomes ";
    if (op.getType() != this->getType())
        this->setType(op.type);
    std::cout << this->getType() << " by Surcharge d'Assignator" << std::endl;
    return (*this);
}

void Cat::makeSound() const{ 
    std::cout << " is Meowing" << std::endl;
}