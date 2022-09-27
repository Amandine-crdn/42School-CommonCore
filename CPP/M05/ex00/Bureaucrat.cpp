#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no_name"), _grade (0) {
    std::cout << "Bureaucrat Default Constructor" << std::endl;
}
Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat Destructor" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat &cp){
    std::cout << "Bureaucrat Constructor Copy" << std::endl;
    this->_name = cp._name;
    this->_grade = cp._grade;
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat &op){
    std::cout << "Bureaucrat Operator Assignement" << std::endl;
    this->_name = op._name;
    this->_grade = op._grade;
    return (*this);
}
Bureaucrat::Bureaucrat(std::string name){
    std::cout << "Bureaucrat Constructor" << std::endl;
    this->_name = name;
    this->_grade = 0;
}

//getters
std::string Bureaucrat::getName() const{ //const std::string du coup
    return (this->_name);
}
int Bureaucrat::getGrade() const{
    return (this->_grade);
}
//setters
void Bureaucrat::setName(std::string name){
    this->_name = name;
}
void Bureaucrat::setGrade(int grade){
    this->_grade = grade;
}

//incrementation, decrementation
void Bureaucrat::operator-(){
    this->_grade++;
}
void Bureaucrat::operator+(){
    this->_grade--;
}

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}