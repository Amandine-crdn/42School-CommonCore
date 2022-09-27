#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Etienne"), _grade (0) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(Bureaucrat const &cp) : _name(cp._name), _grade(cp._grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &op) {
    this->_grade = op._grade;
    return (*this);
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

//getters
const std::string Bureaucrat::getName() const {
    return (this->_name);
}
int Bureaucrat::getGrade() const{
    return (this->_grade);
}

//incrementation, decrementation
void Bureaucrat::operator-(){
    this->_grade++;
    if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
void Bureaucrat::operator+(){
    this->_grade--;
    if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

//exeptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException: Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException: Grade too low!");
}

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}

//function
void Bureaucrat::signForm(Form &form) {
    if (form.beSigned(*this) == 1)
        std::cout << this->_name << " signed " << form.getName() << std::endl; 
    else
        std::cout << this->_name << " couldn't signed " << form.getName() <<
        " because his grade is : " << this->_grade << std::endl; 
}
