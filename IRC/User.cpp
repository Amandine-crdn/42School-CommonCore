#include "User.hpp"

User::User(){
    std::cout << "User Constructor called" << std::endl;
}

User::~User(){
    std::cout << "User Destructor called" << std::endl;
}

void User::addMessages(char *buffer, size_t read_size)
{
	std::string buftemp;
	buftemp.insert(0, buffer, read_size);
	this->setMsg(buftemp);
}

/* getters and setters */

//msg protocol
std::string User::getMsg() const{ return this->message_protocole; }
void User::setMsg(std::string msg) { this->message_protocole = msg; };

//username
void User::setUserName(std::string user_name){this->user_name = user_name;}
std::string User::getUserName(){return (this->user_name);}

//nickname
void User::setNickName(std::string nick_name){this->nick_name = nick_name;};
std::string User::getNickName(){return (this->nick_name);}