#include "Form.hpp"

Form::Form() : _name("no_name"), _gradetosign(0), _gradetoexec(0) , _signed(false) {}

Form::~Form(){}

Form::Form(Form const &cp) : _name(cp._name), _gradetosign(cp._gradetosign), _gradetoexec(cp._gradetoexec), _signed(cp._signed) {}

Form& Form::operator=(Form const &op) {
    this->_signed = op._signed;
    return (*this);
}
Form::Form(const std::string name, const int gts, const int gte) : _name(name), _gradetosign(gts), _gradetoexec(gte), _signed(false) {
    if (this->_gradetosign < 1 || this->_gradetoexec < 1)
		throw Form::GradeTooHighException();
    else if (this->_gradetosign > 150 || this->_gradetoexec > 150)
		throw Form::GradeTooLowException();
}

//getters
const std::string Form::getName() const {
    return (this->_name);
} 
int Form::getGradetosign() const {
    return (this->_gradetosign);
}
int Form::getGradetoexec() const {
     return (this->_gradetoexec);
}
bool Form::getSigned() const {
    return(this->_signed);
}

//exeptions
const char* Form::GradeTooHighException::what() const throw(){
	return ("Form : GradeTooHighException: Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Form : GradeTooLowException: Grade too low!");
}


//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const Form &b){
     os << "Name : " << b.getName() << std::endl << 
     "Form signed ? : " << b.getSigned() << std::endl <<
     "Grade to sign is : " << b.getGradetosign() << std::endl <<
    "Grade to exec : " << b.getGradetoexec() << std::endl;
    return (os);
}

void Form::beSigned(const Bureaucrat &b){
    if (b.getGrade() > this->_gradetoexec || b.getGrade() > this->_gradetosign)
        throw Form::GradeTooLowException();
    else if (b.getGrade() < 1)
        throw Form::GradeTooHighException();
    else
        this->_signed = true;
}