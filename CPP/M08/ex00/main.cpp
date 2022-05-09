#include "easyfind.hpp" 
//std namespace

void testValue(int val, std::vector<int> lst)
{  
    std::cout << val << " -> ";
    try
    {
        easyfind(lst, val);
    }
    catch (std::string str)
    {
        std::cout << str << std::endl;
    }
}

int
main(void)
{
    std::vector<int>    lst;

    lst.push_back(4);
    lst.push_back(8);
    lst.push_back(15);
    lst.push_back(16);
    lst.push_back(23);
    lst.push_back(42);

    testValue(1, lst);
    testValue(4, lst);
    testValue(16, lst);
    testValue(29, lst);
    testValue(42, lst);
    return (0);
}