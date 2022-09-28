#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Etienne", 42);
        Bureaucrat boss("Boss", 1);
        std::cout << bureaucrat << std::endl;
        PresidentialPardonForm presidentForm("Une personne");
        //std::cout << presidentForm << std::endl;  
        presidentForm.beSigned(boss); // signe le formulaire
        //std::cout << presidentForm << std::endl;  
        boss.signAForm(presidentForm); //verification si signer
        //std::cout << presidentForm << std::endl;  
        //presidentForm.execute(bureaucrat); //hide to allow signatre by boss
        presidentForm.execute(boss);


    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}