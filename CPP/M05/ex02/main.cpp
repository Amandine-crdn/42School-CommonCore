#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        std::cout << "\n ***** Initialisation des presonnages ****\n\n";
        Bureaucrat bureaucrat("Etienne", 42);
        std::cout << bureaucrat << std::endl;
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;

        /*  PresidentialPardonForm  */std::cout << "\n1/ ***** PresidentialPardonForm **** \n\n";

        PresidentialPardonForm presidentForm("Une personne");
        std::cout << presidentForm << std::endl;  
        presidentForm.beSigned(boss); // signe le formulaire
        boss.signAForm(presidentForm); //verification si signer
        //presidentForm.execute(bureaucrat); //hide to allow signatre by boss
        presidentForm.execute(boss); //execute

        /*  RobotomyRequestForm  */ std::cout << "\n2/ ***** RobotomyRequestForm **** \n\n";

        RobotomyRequestForm requestForm("Une peluche");
        std::cout << requestForm << std::endl;
        requestForm.beSigned(boss); // signe le formulaire
        boss.signAForm(requestForm); //verification si signer
        //requestForm.execute(bureaucrat); //hide to allow signatre by boss
        requestForm.execute(boss); //execute

        /*  ShrubberyCreationForm  */ std::cout << "\n3/ ***** ShrubberyCreationForm **** \n\n";

        ShrubberyCreationForm creationForm("Un jardin");
        std::cout << creationForm << std::endl;
        creationForm.beSigned(boss); // signe le formulaire
        boss.signAForm(creationForm); //verification si signer
        //creationForm.execute(bureaucrat); //hide to allow signatre by boss
        creationForm.execute(boss); //execute



    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}