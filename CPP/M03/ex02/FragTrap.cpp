#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap Constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) {
    this->_name = name;
    std::cout << "FragTrap Constructor with name : " << this->_name << std::endl << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &op){
    std::cout << "FragTrap Operator=" << std::endl;
    if (&op != this)
        *this = op;
    return (*this);
}

FragTrap::FragTrap(FragTrap const &copy){
    std::cout << "FragTrap Copy" << std::endl;
    *this = copy;
}

void FragTrap::highFivesGuys(void){
    std::cout << "Do you wanna make a hight five ? No reponse please thx u"<< std::endl;
}