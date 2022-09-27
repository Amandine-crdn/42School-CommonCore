#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat agent("agent", 155);
        /* OU
            agent.setGrade(i); // usage setters
            agent.setName("agent");
            std::cout << agent << std::endl; // ma surcharge d'operateur <<
            ou
            SANS RIEN
        */
       // std::cout << "avant : " << agent.getGrade() << std::endl; // usage getter
       // agent.operator-(); //le fait baisser en grade (augmente de 1)
        //std::cout << "apres : "  << agent.getGrade() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    
        // exemple 2 i = 1
        /*agent.setGrade(i);
        std::cout << "avant : " << agent.getGrade() << std::endl;
        agent.operator+(); //le fait augmenter en grade (baisse de 1)
        std::cout << "apres : "  << agent.getGrade() << std::endl;*/
    return (0);
}