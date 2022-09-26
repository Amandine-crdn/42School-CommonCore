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

Cat::Cat( Cat const &cpy ) {
    std::cout << this->getType() << " by Dog Copy Constructor" << std::endl;
    //copy des attributs
    this->type = cpy.type;
    this->_value = cpy._value;
    //copy de Brain *
    this->_brain = new Brain();
    for (int i = 0; i <= getValue(); i++)
    this->_brain->ideas[i] = cpy._brain->ideas[i];
}

Cat& Cat::operator=( Cat const &op ) {
    std::cout << this->getType() << " becomes ";
    //attributs
    this->setType(op.type);
    this->_value = op._value;
    //Brain *
    for (int i = 0; i <= getValue(); i++)
    this->_brain->ideas[i] = op._brain->ideas[i];

    std::cout << this->getType() << " by Dog Surcharge d'Assignator" << std::endl;
    return (*this);
}

void Cat::makeSound() const{ 
    std::cout << " is Meowing" << std::endl;
}

void Cat::setBrain( std::string idea )
{
    static int i = 0; 
    if (i != 100)
    {
        _brain->ideas[i] = idea;
        i++;
        setValue(i);      
    }
}

void Cat::getBrain() const
{
    for (int i = 0; !_brain->ideas[i].empty(); i++)
	std::cout << _brain->ideas[i] << std::endl;
}

void Cat::setValue(int i){
    this->_value = i;
}

int Cat::getValue() const{
    return (this->_value);
}
