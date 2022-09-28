#ifndef PRESIDENTIALPARDONFORM_HPP
#   define PRESIDENTIALPARDONFORM_HPP

#   include <iostream>
#   include <stdexcept>
#   include "Bureaucrat.hpp"

class Bureaucrat ;

class PresidentialPardonForm : public AForm { //que retirer, que mettre en virtual ??

    public :
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &cp);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &op);
        PresidentialPardonForm(std::string target);
        
        //getter
        std::string getTarget() const;

        void execute(Bureaucrat const &executor) const;
        void ft_ask_scuze() const;
    
    private:
        std::string _target;
};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &p);

#endif