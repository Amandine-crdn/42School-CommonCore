#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cp) {
    this->_target = cp._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &op) {

    //*this = op; //suffisant ?
    this->_target = op._target;
    return (*this);
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 25, 5), _target(target) {
}

std::string RobotomyRequestForm::getTarget() const{
    return (this->_target);
}

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &p){
     os << "Name : " << p.getName() << std::endl << 
      "Target : " << p.getTarget() << std::endl <<
     "AForm signed ? : " << p.getSigned() << std::endl <<
     "Grade to sign is : " << p.getGradetosign() << std::endl <<
    "Grade to exec : " << p.getGradetoexec() << std::endl;
    return (os);
}

void RobotomyRequestForm::ft_robotize() const {
    std::cout << " * drill sounds *\n";

    if ((std::rand() % 2) == 0)
        std::cout << this->getTarget() << " was robotized" << std::endl;
    else
        std::cout << this->getTarget() << " wasn't robotized... fail" << std::endl;
}   

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (this->getSigned() == true && executor.getGrade() <= this->getGradetoexec())
    {
        if (!this->getName().compare("RobotomyRequestForm"))
            RobotomyRequestForm::ft_robotize();
    }
    else if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradetoexec())
        throw AForm::GradeTooLowException();
}
