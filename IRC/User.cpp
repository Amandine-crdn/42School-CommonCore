#include "User.hpp"

User::User(){
    std::cout << "User Constructor called" << std::endl;
}

User::~User(){
    std::cout << "User Destructor called" << std::endl;
}

void User::addBufferToMessages(char *buffer, size_t read_size)
{
    std::vector<std::string> _inputMessages; 
	std::string _inputMessagesBuffer; 
	std::string _outputMessage; 
    int pos;
	std::string bufferString;

	bufferString.insert(0, buffer, read_size);
	_inputMessagesBuffer += bufferString;
	while ((pos = _inputMessagesBuffer.find(DELIMITER)) != -1)
	{
		_inputMessages.push_back(_inputMessagesBuffer.substr(0, pos));
		_inputMessagesBuffer.clear();
	}
}

/* getters and setters */

//username
void User::setUserName(std::string user_name){this->user_name = user_name;}
std::string User::getUserName(){return (this->user_name);}

//nickname
void User::setNickName(std::string nick_name){this->nick_name = nick_name;};
std::string User::getNickName(){return (this->nick_name);}