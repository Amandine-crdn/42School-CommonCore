#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Constructor" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain( Brain const &cpy ) { // a check
    *this = cpy; 
    std::cout << "Brain Copy Constructor" << std::endl;
}

Brain& Brain::operator=( Brain const &op ) { // a check
    if (this != &op)
         *this = op;
    std::cout << "Assignement operator" << std::endl;
    return (*this);
}
