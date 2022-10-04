#ifndef AFORM_HPP
#   define AFORM_HPP

#   include <iostream>
#   include <stdexcept>
#   include "Bureaucrat.hpp"
#   include <fstream>

class Bureaucrat ;

class AForm {

    public :
        AForm();
        virtual ~AForm() = 0;
        AForm(AForm const &cp);
        AForm &operator=(AForm const &op);
        AForm(std::string name, const int gts, const int gte);

        //getters
        const std::string getName() const;
        int getGradetosign() const;
        int getGradetoexec() const;
        bool getSigned() const;
        
        //functions
        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const &executor) const = 0;

        //class exception
        class GradeTooHighException : public std::exception {
            public :
                virtual const char * what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public :
                virtual const char * what() const throw();
        };
        class NotSignedException : public std::exception {
            public :
                virtual const char * what() const throw();
        };
        class ErrorOpen : public std::exception {
            public :
                virtual const char * what() const throw();
        };

    private :
        const std::string _name;
        const int _gradetosign;
        const int _gradetoexec;
        bool _signed;


};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif