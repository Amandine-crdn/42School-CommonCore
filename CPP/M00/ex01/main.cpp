#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    PhoneBook repertoire;

    std::string add ("ADD");
    std::string input;
    std::string exit ("EXIT");
    std::string search ("SEARCH");

    if(argc == 1)
    {
        std::cout << "You can ADD, SEARCH or EXIT, it's your choice !" << std::endl;
        while (1)
        {  
            std::getline(std::cin, input);
            if  (std::cin.eof() || input.compare(exit) == 0 && input.size() == exit.size())
            {
                std::cout << "\nGood bye !" << std::endl;
                break ;
            }
            else if  (input.compare(add) == 0) // ADD toto ne doit pas marcher //eof
            {
                std::cout << "\nGo add one person !\n" << std::endl;
                repertoire.add_contact();
            }
            else if  (input.compare(search) == 0 && input.size() == search.size())
            {
                std::cout << "\nYou search somebody ?\n" << std::endl;
                repertoire.print_contact();
            }
        }
    }
    return 0;
    
}