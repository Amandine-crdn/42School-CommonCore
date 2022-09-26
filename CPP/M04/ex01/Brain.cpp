#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Constructor" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain( Brain const &cpy ) {
    for (int i = 0; i < this->_nb_ideas; i++)
    this->ideas[i] = cpy.ideas[i];
    std::cout << "Brain Copy Constructor" << std::endl;
}

Brain& Brain::operator=( Brain const &op ) {
    if (this != &op)
    {
       for (int i = 0; i < this->_nb_ideas; i++)
       this->ideas[i] = op.ideas[i];
    }
    std::cout << "Brain Assignement operator" << std::endl;
    return (*this);
}
