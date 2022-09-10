#include <iostream>

int main(int argc, char **argv)
{
    std::string new_arg;
    std::string::iterator it;
    int y;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            new_arg = argv[i];
            for(it = new_arg.begin(); it < new_arg.end(); it++)
            {
                y = 0;
                new_arg[y] = *it;
                std::cout <<  (char)std::toupper(new_arg[y]);
            }
            std::cout << std::endl;
        }
    }
    return (0); 
}