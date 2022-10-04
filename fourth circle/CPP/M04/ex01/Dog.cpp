#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog Constructor Default" << std::endl;
    this->_brain = NULL;
    this->_brain = new Brain();
}

Dog::~Dog() {
    delete this->_brain;   
    std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog( Dog const &cpy ) {
    std::cout << this->getType() << " by Dog Copy Constructor" << std::endl;
    //copy des attributs
    this->type = cpy.type;
    this->_value = cpy._value;
    //copy de Brain *
    this->_brain = new Brain();
    for (int i = 0; i <= getValue(); i++)
    this->_brain->ideas[i] = cpy._brain->ideas[i];
}

Dog& Dog::operator=( Dog const &op ) {
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

void Dog::makeSound() const{ 
    std::cout << " is Wouaaaf" << std::endl;
}

void Dog::setBrain( std::string idea )
{
    static int i = 0; 
    if (i != 100)
    {
        _brain->ideas[i] = idea;
        i++;
        setValue(i);      
    }
}

void Dog::getBrain() const
{
    for (int i = 0; !_brain->ideas[i].empty(); i++)
	std::cout << _brain->ideas[i] << std::endl;
}

void Dog::setValue(int i){
    this->_value = i;
}

int Dog::getValue() const{
    return (this->_value);
}
