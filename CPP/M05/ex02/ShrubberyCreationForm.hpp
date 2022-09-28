#ifndef SHRUBBERYCREATIONFORM_HPP
#   define SHRUBBERYCREATIONFORM_HPP

#   include <iostream>
#   include <stdexcept>
#   include "Bureaucrat.hpp"

class Bureaucrat ;

class ShrubberyCreationForm : public AForm {

    public :
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &cp);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &op);
        ShrubberyCreationForm(std::string target);
        
        //getter
        std::string getTarget() const;

        void execute(Bureaucrat const &executor) const;
        void ft_forest() const;
    
    private:
        std::string _target;
};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &p);

#endif