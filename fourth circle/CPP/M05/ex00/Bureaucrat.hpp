#ifndef BUREAUCRAT_HPP
#   define BUREAUCRAT_HPP
#   include <iostream>
#   include <stdexcept>

class Bureaucrat {

    public :
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &cp);
        Bureaucrat &operator=(Bureaucrat const &op);
        Bureaucrat(const std::string name, int grade);

        //getters
        const std::string getName() const;
        int getGrade() const;

        //incrementation, decrementation
        void operator-();
        void operator+();

        //class exception
        class GradeTooHighException : public std::exception {
            public :
                virtual const char * what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public :
                virtual const char * what() const throw();
        };
    private :
        const std::string _name;
        int _grade;

};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif