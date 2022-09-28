#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no name"), _grade (0) {}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(Bureaucrat const &cp) : _name(cp._name), _grade(cp._grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &op) {
    this->_grade = op._grade;
    return (*this);
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
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
    if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}
void Bureaucrat::operator+(){
    if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

//exeptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat : GradeTooHighException: Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat : GradeTooLowException: Grade too low!");
}

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}

//function
void Bureaucrat::signForm(Form &form) {
    if (form.getSigned() == true)
        std::cout << this->_name << " signed " << form.getName() << std::endl; 
    else
        std::cout << this->_name << " couldn't signed " << form.getName() <<
        " because he doesn't have the form in his hands may be!"<< std::endl; 
}
