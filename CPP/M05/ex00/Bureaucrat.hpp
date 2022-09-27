#ifndef BUREAUCRAT_HPP
#   define BUREAUCRAT_HPP
#   include <iostream>
#   include <stdexcept>

class Bureaucrat {

    public :
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(Bureaucrat &cp);
        Bureaucrat &operator=(Bureaucrat &op);
        Bureaucrat(std::string name);

        //getter et setter
        std::string getName() const;//const std::string du coup
        int getGrade() const;
        void setName(std::string name);
        void setGrade(int grade);

        //incrementation, decrementation
        void operator-();
        void operator+();

        //class exception
        class GradeTooHighException {
            public :
                virtual const char * what() const throw()
                {
                    return ("PROBLEME HIGHT");
                }
        };
        class GradeTooLowException {
            public :
                virtual const char * what() const throw()
                {
                    return ("PROBLEME LOW");
                }
        };
    private :
        std::string _name; //const string attendu par le sujet
        int _grade;

};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif