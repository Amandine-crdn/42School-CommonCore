#include "Harl.hpp"

int main()
{
    Harl harl;
   
    int life = 10;

    while (life)
    {
        harl.complain("DEBUG");
        harl.complain("WARNING");
        harl.complain("INFO");
        harl.complain("ERROR");
        std::cout << "--------" <<std::endl;
        life--;
    }
    
    return (0);
}