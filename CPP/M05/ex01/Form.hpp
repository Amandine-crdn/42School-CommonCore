#ifndef FORM_HPP
#   define FORM_HPP

#   include <iostream>
#   include <stdexcept>
#   include "Bureaucrat.hpp"

class Bureaucrat ;

class Form {

    public :
        Form();
        ~Form();
        Form(Form const &cp);
        Form &operator=(Form const &op);
        Form(std::string name, const int gts, const int gte);

        //getters
        const std::string getName() const;
        int getGradetosign() const; //ne veut pas de const int ?
        int getGradetoexec() const;
        bool getSigned() const;

        //functions
        int beSigned(const Bureaucrat &b);

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
        const int _gradetosign;
        const int _gradetoexec; // diff ??
        bool _signed;

};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Form &b);

#endif