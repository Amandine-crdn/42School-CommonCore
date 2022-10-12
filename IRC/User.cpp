#include "User.hpp"

User::User() : first_connexion(true) {
    std::cout << "User Constructor called" << std::endl; }

User::~User(){
    std::cout << "User Destructor called" << std::endl; }


/* methods */

void User::addMessages(char *buffer, size_t read_size) {
	std::string buftemp;
	buftemp.insert(0, buffer, read_size);
	this->setMsg(buftemp); }

/* getters and setters */

//msg protocol
std::string User::getMsg() const{ return this->message_protocole; }
void User::setMsg(std::string msg) { this->message_protocole = msg; };

//username
void User::setUserName(std::string user_name){ this->user_name = user_name; }
std::string User::getUserName(){ return this->user_name; }

//nickname
void User::setNickName(std::string nick_name){ this->nick_name = nick_name; };
std::string User::getNickName(){ return this->nick_name; }

//firt connexion
bool User::getFirstConnexion() const { return this->first_connexion; }
void User::setFirstConnexion(bool choice) { this->first_connexion = choice; }

//fd
void User::setFd(int fd) { this->fd = fd; }
int User::getFd() const { return this->fd; }