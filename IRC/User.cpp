#	include "User.hpp"

User::User() : nick_name("somebody"), user_name("an username"),first_connexion(true), IRCOperator(false) {}
	
User::~User() {}


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
}


std::string User::getFullClientIdentifier(void) 
{
	//<nick>!<user>@<host>
	return this->getNickName() + "!" + this->getUserName() + "@" + this->getUserName(); 
}

void User::setUserName(std::string user_name){ this->user_name = user_name; }
std::string User::getUserName(){ return this->user_name; }

void User::setNickName(std::string nick_name){ this->nick_name = nick_name; };
std::string User::getNickName(){ return this->nick_name; }

bool User::getFirstConnexion() const { return this->first_connexion; }
void User::setFirstConnexion(bool choice) { this->first_connexion = choice; }

void User::setFd(int fd) { this->fd = fd; }
int User::getFd() const { return this->fd; }

bool User::getVisibility() const { return this->visibility; }
void User::setVisibility(bool choice) { this->visibility = choice; }

bool User::getIRCOper() const { return this->IRCOperator; };
void User::setIRCOper(bool choice) { this->IRCOperator = choice; };

//liste de course des channels
std::vector<std::string> User::getChannelListByUser() const { return this->channels_list_by_user; }
void User::setChannelListByUser(std::string new_channel) {
 
		channels_list_by_user.push_back(new_channel);

		std::cout << "listes channel for " << this->getNickName() << " :\n";
		 for(std::vector<std::string>::iterator po = channels_list_by_user.begin(); po != channels_list_by_user.end(); po++)
		 {
			 std::cout << "-> " << *po << std::endl;
		 }
 }  
 

std::vector<std::string> User::getChannops(void) const { return channops; }
void User::setChannops(std::string channel) {

		  channops.push_back(channel);

		std::cout << "channops for " << this->getNickName() << " :\n";
		 for(std::vector<std::string>::iterator po = channels_list_by_user.begin(); po != channels_list_by_user.end(); po++)
		 {
			 std::cout << "-> " << *po << std::endl;
		 }
		 }