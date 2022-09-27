#ifndef FORM_HPP
#   define FORM_HPP
#   include <iostream>
#   include <stdexcept>

class Form {

    public :
        Form();
        ~Form();
        Form(Form &cp);
        Form &operator=(Form &op);
        Form(std::string name);

        //getter et setter
        std::string getName() const;//const std::string du coup
        int getGrade() const;
        void setName(std::string name);
        void setGrade(int grade);

        //incrementation, decrementation
        void operator-();
        void operator+();

        //class exception
        class GradeTooHighException { //faut-il leur creer des constructeur et destructeur ? (pas cooplenne ok)
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
        const int _gradetosign; //const int ici
        const int _gradetoexec; //const int ici
        bool _signed;

};

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Form &b);

#endif