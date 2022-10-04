#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

//copy
Intern::Intern(Intern const &cp) {
    *this = cp;
}
Intern& Intern::operator=(Intern const &op) {
    if (this != &op)
        *this = op;
    return (*this);
}

AForm *Intern::makeForm(std::string name_form, std::string target_form) const {
    int i;

    std::string nameForm[] = {
        "shrubbery creation",
		"robotomy request",
		"presidential pardon",
    };

    for (i = 0; i < 3 && name_form != nameForm[i]; i++);
    
    if (i >= 0 && i <= 2)
        std::cout << " ***** Intern creates " << nameForm[i] << " *****" << std::endl;

    switch (i)
    {
        case 0: return (new ShrubberyCreationForm(target_form));
        case 1: return (new RobotomyRequestForm(target_form));
        case 2: return (new PresidentialPardonForm(target_form)); break;
    
        default:
        {
           std::cout << "Intern can't creates " << name_form << " cause it doesn't exists" << std::endl;
            break;
        }
    }
    return (NULL);
}

