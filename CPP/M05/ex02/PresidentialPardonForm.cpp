#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cp) {
    this->_target = cp._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &op) {

    //*this = op; //suffisant ?
    this->_target = op._target;
    return (*this);
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

std::string PresidentialPardonForm::getTarget() const{
    return (this->_target);
}

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &p){
     os << "Name : " << p.getName() << std::endl << 
      "Target : " << p.getTarget() << std::endl <<
     "AForm signed ? : " << p.getSigned() << std::endl <<
     "Grade to sign is : " << p.getGradetosign() << std::endl <<
    "Grade to exec : " << p.getGradetoexec() << std::endl;
    return (os);
}


void PresidentialPardonForm::ft_ask_scuze() const {
    std::cout << "j'implemente une fonction pour executer le pardon presidentielle" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (this->getSigned() == true && executor.getGrade() <= this->getGradetoexec())
    {
        if (!this->getName().compare("PresidentialPardonForm"))
            PresidentialPardonForm::ft_ask_scuze();
    }
    else if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradetoexec())
        throw AForm::GradeTooLowException();
}
