#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Etienne", 42);
        std::cout << bureaucrat << std::endl;
        Form secret("secret", 42, 42);
        std::cout << secret << std::endl;
        secret.beSigned(bureaucrat); //hide to allow else signform
        bureaucrat.signForm(secret);
        Form strangeForm("strangeForm", 120, 120);
        strangeForm.beSigned(bureaucrat);
        std::cout << strangeForm << std::endl;
        bureaucrat.signForm(strangeForm);
        Form onlyBoss("onlyBoss", 1, 1);
        std::cout << onlyBoss << std::endl;
        onlyBoss.beSigned(bureaucrat);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}