#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <map>


void displayInt(int i)
{
    std::cout << "i = " << i << std::endl;
}

int main()
{
    /* FOR VECTOR */
 
        int i = 20;
        int myints[] = {10, 20, 30, 40};
        std::vector<int> myvector (myints,myints+4);
        if (::easyfind(myvector, i) == myvector.end())
            std::cerr << "error" << std::endl;
        else
            std::cout << "FIND !" << std::endl;

    /* FOR LIST */

        int y = 10;
        std::list<int> lst;
        lst.push_back(30);
        lst.push_back(220);
        lst.push_back(20);
        lst.push_back(10);
        if (::easyfind(lst, y) == lst.end())
            std::cerr << "error" << std::endl;
        else
            std::cout << "FIND !" << std::endl;

return (0);
}