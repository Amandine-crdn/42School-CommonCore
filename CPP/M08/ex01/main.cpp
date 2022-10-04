#include "Span.hpp"
#include <iostream>
#include <list>
#include <map>

int main()
{
    /* FIRST TEST FOR TAB */
  
  Span test(3);

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
    



            // test.addNumber(20);
            // test.addNumber(30);
            // std::cout << test.getValueTab(2) << std::endl;
           // std::cout << test << std::endl; 
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


return (0);
}