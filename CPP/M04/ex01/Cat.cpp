#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat Constructor" << std::endl;
    this->_brain = new Brain();
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat( Cat const &cpy ) : Animal() {
    this->type = cpy.type; 
    std::cout << this->getType() << " by Cat Copy Constructor" << std::endl;
}

Cat& Cat::operator=( Cat const &op ) {
   std::cout << this->getType() << " becomes ";
    if (op.getType() != this->getType())
        this->setType(op.type);
    std::cout << this->getType() << " by Cat Surcharge d'Assignator" << std::endl;
    return (*this);
}

void Cat::makeSound() const{ 
    std::cout << " is Meowing" << std::endl;
}