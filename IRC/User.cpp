#include "User.hpp"

User::User(){
    std::cout << "User Constructor called" << std::endl;
}

User::~User(){
    std::cout << "User Destructor called" << std::endl;
}



/* getters and setters */

//username
void User::setUserName(std::string user_name){this->user_name = user_name;}
std::string User::getUserName(){return (this->user_name);}

//nickname
void User::setNickName(std::string nick_name){this->nick_name = nick_name;};
std::string User::getNickName(){return (this->nick_name);}