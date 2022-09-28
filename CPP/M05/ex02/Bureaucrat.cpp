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
    if (this->_grade >= 150) // ne peut pas descendre en dessous de 150
		throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}
void Bureaucrat::operator+(){ // ne peut pas augmenter au dessus de 1
    if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

//exeptions
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Bureaucrat : GradeTooHighException: Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Bureaucrat : GradeTooLowException: Grade too low!");
}

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}

//function
void Bureaucrat::signForm(AForm &AForm) {
    if (AForm.getSigned() == true)
        std::cout << this->_name << " signed " << AForm.getName() << std::endl; 
    else
        std::cout << this->_name << " couldn't signed " << AForm.getName() <<
        " because he doesn't have the AForm in his hands may be!"<< std::endl; 
}

void Bureaucrat::executeForm(AForm const &form){
    if (this->getGrade() <= form.getGradetoexec() && form.getSigned() == true)
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    else
    {
        std::cout << this->getName() << " can't executed " << form.getName() << std::endl;
        std::cout << "He must have a grade more higher than " << form.getGradetoexec() <<
        " cause he have a grade at : " << this->getGrade() << std::endl;
        std::cout << "You can change bureaucrat" << std::endl;
    }
}