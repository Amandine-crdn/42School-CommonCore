#include "Array.hpp"

int main()
{
    std::cout << "\n****************** TABLEAU INT VIDE***************\n" << std::endl;
    Array<int> empty;
    std::cout << "empty[" << 0 << "] = " << empty[0] << std::endl;
    std::cout << "empty[" << 1 << "] = " << empty[1] << std::endl;

    std::cout << "\n****************** TABLEAU INT INITIALISER PAR DEFAUT ***************\n" << std::endl;
    int * a = new int(); 
    Array<int> dodo(5);
    std::cout << "exemple du sujet : " << *a << std::endl;
    std::cout << "\ndodo[" << 0 << "] = " << dodo[0] << std::endl;
    std::cout << "dodo[" << 1 << "] = " << dodo[1] << std::endl;

    std::cout << "\n****************** TABLEAU UNSIGNED INT ***************\n" << std::endl;

    unsigned int size = 4;
    Array<int> j(size);
    j[0] = 0;
    j[1] = 2;
    j[2] = 4;
    j[3] = 6;

    std::cout << "\nTableau d'int : \n" << std::endl;
    for (unsigned int i = 0; i < j.size(); i++)
    std::cout << "j[" << i << "] = " << j[i] << std::endl;

    Array<int> copy = j;
    std::cout << "\nTableau d'int copy : \n" << std::endl;
    for (unsigned int i = 0; i < j.size(); i++)
    std::cout << "copy[" << i << "] = " << copy[i] << std::endl;


    std::cout << "\n****************** TABLEAU STRING ***************\n" << std::endl;


    Array<std::string> str(2);

    str[0] = "test";
    str[1] = "plop";

    std::cout << "Tableau de string : \n" << std::endl;
    for (unsigned int i = 0; i < str.size(); i++)
    std::cout << "str[" << i << "] = " << str[i] << std::endl;

    std::cout << "\nCopy de string : \n" << std::endl;
    Array<std::string> strcopy(str);
    for (unsigned int i = 0; i < strcopy.size(); i++)
    std::cout << "strcopy[" << i << "] = " << strcopy[i] << std::endl;
    // + une modification
    strcopy[0] = "murp";
    
    std::cout << std::endl;
    for (unsigned int i = 0; i < strcopy.size(); i++)
    std::cout << "strcopy modifier [" << i << "] = " << strcopy[i] << std::endl;

    std::cout << "\n ***** Verification si l'autre arret changer ou pas *****\n " << std::endl;
     std::cout << "Tableau de string : \n" << std::endl;
    for (unsigned int i = 0; i < str.size(); i++)
    std::cout << "str[" << i << "] = " << str[i] << std::endl;

    std::cout << std::endl;
    std::cout << "**** CALL EXEPTION *** " << std::endl;

    try
    {
        std::cout << j[j.size() + 1] << std::endl;
    }
    catch (std::exception &e)
    {
         std::cout << "Yes it's an EXCEPTION " << std::endl;
    }
}