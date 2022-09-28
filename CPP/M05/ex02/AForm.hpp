#ifndef AFORM_HPP
#   define AFORM_HPP

#   include <iostream>
#   include <stdexcept>
#   include "Bureaucrat.hpp"

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
        int getGradetosign() const; //ne veut pas de const int ?
        int getGradetoexec() const;
        bool getSigned() const;

        //setters
        void setName(std::string name);
        void setGradetosign(int grade); 
        void setGradetoexec(int grade);
        void setSigned();

        //functions
        void beSigned(const Bureaucrat &b); //virtual ??
        void execute(Bureaucrat const &executor) const; //new fonctions

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
        const int _gradetoexec;
        bool _signed;

};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const AForm &b);

#endif