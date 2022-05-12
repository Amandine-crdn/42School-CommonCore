#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string mdp;

   

    while (1)
    {
        std::cout << "Choisis le level de Harl" << std::endl;
        std::cout << "[DEBUG] [INFO] [WARNING] [ERROR]" << std::endl;
        
        std::cout << "Enter the  string" << std::endl;
        std::cin >> mdp;
        harl.complain(mdp);
        std::cout << std::endl; 
    }
    
}