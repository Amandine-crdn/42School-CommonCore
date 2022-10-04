#include "Span.hpp"
#include <iostream>
#include <list>
#include <map>

int main()
{
    /* FIRST TEST FOR TAB */
  
    /*Span test(3);

    try {
        std::cout << test.getCount() << std::endl;
        test.addNumber(10);
        std::cout << test.getCount() << std::endl;
        test.addNumber(20);
        std::cout << test.getCount() << std::endl;
        test.addNumber(50);
        //std::cout << test.getCount() << std::endl; // exeption
        //test.addNumber(10);
        std::cout << std::endl;
        std::cout << test << std::endl;
    }
    catch (Span::NoMoreException &e)
    {
        std::cout << "Span : NoMoreException: is full" << std::endl;
    }
    catch (Span::InconnuValue &e)
    {
        std::cout << "Span : InconnuValue: sorry is not permissed" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Other exeption" << std::endl;
    }
*/


    /* NEXT LEVEL TEST FOR TAB */
        /*Span test(3);
        test.addNumber(19); // hide one and two
        test.addNumber(15);
        test.addNumber(18);*/
        
    /* TEST MAIN ENONCE */
    
        /*test.addNumber(6);
        Span test(5);
        test.addNumber(3);
        test.addNumber(17);
        test.addNumber(9);
        test.addNumber(11);*/
   /* try {
        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Catching exeption" << std::endl;
    }
*/



    /* ITERATOR ADD */
   /* static const int forAll = 17;
    Span test(forAll);
    std::vector<int> vec;
    int list[forAll] = {1, 600, 33, -9, 0, 13, 740, 2, 3, 4, 5, 80, 90, 70, 700, 9000, 11};
    
    for(int i = 0; i != forAll; i++)
    vec.push_back(list[i]);
    
    test.addLotof(vec);
    std::cout << test << std::endl;*/


    /* TEST CONSTRUCTEUR PAR COPIE + operator=*/

   /* Span copy(test);
    std::cout << "copy = \n" << copy << std::endl;
    std::cout << "copy.getCount = " << copy.getCount() << std::endl;

    Span egal(copy);
    std::cout << "egal = \n" << egal << std::endl;
    std::cout << "egal.getCount = " << egal.getCount() << std::endl;*/

return (0);
}