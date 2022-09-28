#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
     /* TEST DE COPY + OPERATOR EGAL */std::cout << "\n0/ ***** TEST DE COPY + OPERATOR EGAL **** \n\n";

    PresidentialPardonForm cc("jardin");
    std::cout << cc << std::endl;
    PresidentialPardonForm copy = cc;
    std::cout << copy << std::endl;
    PresidentialPardonForm copy2 = copy;
    std::cout << copy2 << std::endl;


   srand((unsigned)time(0));
    try
    {
        std::cout << "\n ***** Initialisation des personnages ****\n\n";
        Bureaucrat bureaucrat("Etienne", 42); // too low
        std::cout << bureaucrat << std::endl;
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;

        /*  PresidentialPardonForm  */std::cout << "\n1/ ***** PresidentialPardonForm **** \n\n";

        PresidentialPardonForm presidentForm("Une personne");
        std::cout << presidentForm << std::endl;  
        presidentForm.beSigned(boss); // signe le formulaire
        boss.signForm(presidentForm); //verification si signer
        //presidentForm.execute(bureaucrat); // too low
         presidentForm.execute(boss); //execute
    }
    catch(PresidentialPardonForm::GradeTooLowException &e)
    {
        std::cerr << e.what() << "\nGRRRR you're emploiement is terminated, you're fired !" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    ////////////////////////////////////////////////////////////////////////////

    try
    {
        std::cout << "\n ***** Initialisation des personnages ****\n\n";
        Bureaucrat bureaucrat("Etienne", 42); // too low
        Bureaucrat boss("Boss", 1);

        /*  RobotomyRequestForm  */ std::cout << "\n2/ ***** RobotomyRequestForm **** \n\n";

        RobotomyRequestForm requestForm("Une peluche");
        std::cout << requestForm << std::endl;
        requestForm.beSigned(boss); // hide to appear AForm exception
        boss.signForm(requestForm); //verification si signer
        //requestForm.execute(bureaucrat); // too low
        requestForm.execute(boss); //execute
    }
    catch(RobotomyRequestForm::GradeTooHighException &e)
    {
        std::cerr << e.what() << "\nYou've obtain promotion, you change job !" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

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
        boss.signForm(creationForm); //verification si signer
        bureaucrat.executeForm(creationForm); //verif s'il peut executer
        boss.executeForm(creationForm); //verif s'il peut executer
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