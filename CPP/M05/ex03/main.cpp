#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern anIntern;
    AForm* rrf;
    rrf = anIntern.makeForm("toto pardon", "Bender");
    //rrf = anIntern.makeForm("presidential pardon", "Bender");
    if (rrf != NULL)
    {
        std::cout << rrf->getName() << std::endl;
        std::cout << rrf->getGradetoexec() << std::endl;
        std::cout << rrf->getGradetosign() << std::endl;
        std::cout << rrf->getTarget() << std::endl;
        delete rrf;
    }
    return (0);
}