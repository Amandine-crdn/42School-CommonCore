#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 0)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    if (argc == 1)
        std::cout << "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." << std::endl;
    if (argc > 1)
        std::cout << "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." << std::endl;
    return 0;
}
