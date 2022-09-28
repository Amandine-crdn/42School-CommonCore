#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cp) {
    this->_target = cp._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &op) {

    //*this = op; //suffisant ?
    this->_target = op._target;
    return (*this);
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 25, 5), _target(target) {
}

std::string ShrubberyCreationForm::getTarget() const{
    return (this->_target);
}

//surcharge d'operateur d'insertion
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &p){
     os << "Name : " << p.getName() << std::endl << 
      "Target : " << p.getTarget() << std::endl <<
     "AForm signed ? : " << p.getSigned() << std::endl <<
     "Grade to sign is : " << p.getGradetosign() << std::endl <<
    "Grade to exec : " << p.getGradetoexec() << std::endl;
    return (os);
}

void ShrubberyCreationForm::ft_forest() const {
    
    std::string     filename = this->getTarget().append("_shrubbery");
    std::ofstream   ofs(filename.c_str(), std::ios::out | std::ios::trunc); 
    if(ofs.fail() || !ofs.is_open())
        throw AForm::ErrorOpen();
    else
        ofs << "                 __..-----')\n       ,.--._ .-'_..--...-'\n       '-\"'. _/_ /  ..--''\"\"'-.\n         _.--""...:._:(_ ..:\"::. \n     .-' ..::--\"\"_(##)#)\"':. \\ \\)    \\ _|_ /\n    /_:-:'/  :__(##)##)    ): )   '-./'   '\\.-'\n    \"  / |  :' :/\"\"\\///)  /:.'    --(       )--\n      / :( :( :(   (#//)  \"       .-'\\.___./'-.\n     / :/|\\ :\\_:\\   \\#//\\            /  |  \\\n     |:/ | \"\"--':\\   (#//)              '\n     \\/  \\ :|  \\ :\\  (#//)\n          \\:\\   '.':. \\#//\\\n           ':|    \"--'(#///)\n                      (#///)\n                      (#///)  \n                       \\#///\\   \n                       (##///)       \n                       (##///)    \n                       (##///)       \n                       (##///)       \n                        \\##///\\      \n                        (###///)     \n                        (sjw////)__";
    std::cout << "j'implemente un fichier <target> dans le repertoire courant \
pour faire une foret d'arbre en ASCII a linterieur" << std::endl;
    ofs.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (this->getSigned() == true && executor.getGrade() <= this->getGradetoexec())
    {
        if (!this->getName().compare("ShrubberyCreationForm"))
            ShrubberyCreationForm::ft_forest();
    }
    else if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradetoexec())
        throw AForm::GradeTooLowException();
}
