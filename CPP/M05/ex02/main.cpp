#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    // try
    // {
    //     std::cout << "\n ***** Initialisation des personnages ****\n\n";
    //     Bureaucrat bureaucrat("Etienne", 42); // too low
    //     std::cout << bureaucrat << std::endl;
    //     Bureaucrat boss("Boss", 1);
    //     std::cout << boss << std::endl;

    //     /*  PresidentialPardonForm  */std::cout << "\n1/ ***** PresidentialPardonForm **** \n\n";

    //     PresidentialPardonForm presidentForm("Une personne");
    //     std::cout << presidentForm << std::endl;  
    //     presidentForm.beSigned(boss); // signe le formulaire
    //     boss.signAForm(presidentForm); //verification si signer
    //     //presidentForm.execute(bureaucrat); // too low
    //      presidentForm.execute(boss); //execute
    // }
    // catch(PresidentialPardonForm::GradeTooLowException &e)
    // {
    //     std::cerr << e.what() << "\nGRRRR you're emploiement is terminated, you're fired !" << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    // ////////////////////////////////////////////////////////////////////////////

    // try
    // {
    //     std::cout << "\n ***** Initialisation des personnages ****\n\n";
    //     Bureaucrat bureaucrat("Etienne", 42); // too low
    //     Bureaucrat boss("Boss", 1);

    //     /*  RobotomyRequestForm  */ std::cout << "\n2/ ***** RobotomyRequestForm **** \n\n";

    //     RobotomyRequestForm requestForm("Une peluche");
    //     std::cout << requestForm << std::endl;
    //     requestForm.beSigned(boss); // hide to appear AForm exception
    //     boss.signAForm(requestForm); //verification si signer
    //     //requestForm.execute(bureaucrat); // too low
    //     requestForm.execute(boss); //execute
    // }
    // catch(RobotomyRequestForm::GradeTooHighException &e)
    // {
    //     std::cerr << e.what() << "\nYou've obtain promotion, you change job !" << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // ////////////////////////////////////////////////////////////////////////////

    try
    {
        std::cout << "\n ***** Initialisation des personnages ****\n\n";
        Bureaucrat bureaucrat("Etienne", 42);
        std::cout << bureaucrat << std::endl;
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;

        /*  ShrubberyCreationForm  */ std::cout << "\n3/ ***** ShrubberyCreationForm **** \n\n";

        ShrubberyCreationForm creationForm("Un jardin");
        std::cout << creationForm << std::endl;
        creationForm.beSigned(boss); // signe le formulaire
        boss.signAForm(creationForm); //verification si signer
       // creationForm.execute(bureaucrat); //hide to allow signatre by boss
        creationForm.execute(boss); //execute without exception

    }
    catch(ShrubberyCreationForm::NotSignedException &e)
    {
        std::cerr << e.what() << "\nYou may signed this document!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}