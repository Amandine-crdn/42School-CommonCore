#ifndef ROBOTOMYREQUESTFORM_HPP
#   define ROBOTOMYREQUESTFORM_HPP

#   include <iostream>
#   include <stdexcept>
#   include "Bureaucrat.hpp"

class Bureaucrat ;

class RobotomyRequestForm : public AForm {

    public :
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &cp);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &op);
        RobotomyRequestForm(std::string target);
        
        //getter
        std::string getTarget() const;

        void execute(Bureaucrat const &executor) const;
        void ft_robotize() const;
    
    private:
        std::string _target;
};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &p);

#endif