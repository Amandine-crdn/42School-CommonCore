#include "Bureaucrat.hpp"

int main()
{
    int i = 0; // pour try
    Bureaucrat agent("agent");
   
    Bureaucrat::GradeTooHighException tooHight;
    Bureaucrat::GradeTooLowException tooLow;
    agent.setGrade(10); //avec et sans cette ligne a tester
    std::cout << agent << std::endl; // ma surcharge d'operateur <<
    try {
        //exemple 1 i = 150
        /*agent.setGrade(i); // usage setter
        std::cout << "avant : " << agent.getGrade() << std::endl; // usage getter
        agent.operator-(); //le fait baisser en grade (augmente de 1)
        std::cout << "apres : "  << agent.getGrade() << std::endl;*/
        
        // exemple 2 i = 1
        /*agent.setGrade(i);
        std::cout << "avant : " << agent.getGrade() << std::endl;
        agent.operator+(); //le fait augmenter en grade (baisse de 1)
        std::cout << "apres : "  << agent.getGrade() << std::endl;*/

        if (agent.getGrade() < 1 || agent.getGrade() > 150) {
            throw std::exception();
        }
        else {
            agent.setGrade(i);
        }
    }
    catch (std::exception e){
        std::cerr << "Error not valid grade" << std::endl;
    }
    
    return (0);
}