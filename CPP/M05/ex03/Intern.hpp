#ifndef INTERN_HPP
#   define INTERN_HPP
#   include "AForm.hpp"
#   include "ShrubberyCreationForm.hpp"
#   include "RobotomyRequestForm.hpp"
#   include "PresidentialPardonForm.hpp"

class AForm;

class Intern {

    public  :
        Intern();
        ~Intern();
        Intern(Intern const &cp);
        Intern &operator=(Intern const &op);

        AForm *makeForm(std::string name_form, std::string target_form) const;

    private :
        
};

#endif