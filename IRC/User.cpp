#include "User.hpp"

User::User() : first_connexion(true) {
    std::cout << "User Constructor called" << std::endl; }

User::~User(){
    std::cout << "User Destructor called" << std::endl; }



/*------ methods ------- */


 void User::eraseMsg()
 {
	std::vector<std::string>::iterator it;
	it = vector_message_protocole.begin();
	std::vector<std::string>::iterator end;
	end = vector_message_protocole.end();
	vector_message_protocole.erase(it, end);
 }


/*------ getters and setters ------ */


//msg protocol
std::vector<std::string> User::getMsg() const{ return this->vector_message_protocole; } 
void User::setMsg(char *buffer, size_t read_size)
{
	int pos;
	std::string bufferString;
	std::string temp;

	bufferString.insert(0, buffer, read_size);
	temp += bufferString;
	while ((pos = temp.find(DELIMITER)) != -1) {
		vector_message_protocole.push_back(temp.substr(0, pos));
		temp = temp.erase(0, pos + sizeof(DELIMITER) - 1); }

	for (std::vector<std::string>::iterator it = vector_message_protocole.begin() ; it != vector_message_protocole.end(); it++)
	std::cout << "⌛  🖥️  IRSSI = >" << *it << "<" << std::endl;
	std::cout << std::endl;
}

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