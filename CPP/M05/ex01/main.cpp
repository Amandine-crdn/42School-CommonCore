#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "1\n";
        Bureaucrat bureaucrat("Etienne", 42);
        std::cout << "2\n";
        Form secret("secret", 10, 10);
        std::cout << secret << std::endl;
        bureaucrat.signForm(secret);
        std::cout << "3\n";
        Form nomalForm("nomalForm", 120, 120);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}