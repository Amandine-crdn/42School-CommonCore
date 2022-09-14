#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        Harl harl;
        std::string level_spe = argv[1];

        harl.complain(level_spe);
    }
    else
        std::cout << "Need 1 param" << std::endl;
    
    return (0);
}