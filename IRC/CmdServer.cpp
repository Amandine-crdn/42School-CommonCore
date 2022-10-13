#include "Server.hpp"

/* ------ Methods ------*/


std::string Server::passCmd(User &user, std::vector<std::string> data)
{
    std::string password = "";

	if (data[1].compare(this->getPassword()) == 0) {
         password = data[1];
         std::cout << "\t\t✅ Great password" << std::endl; }
	else {
	    std::cout << "\t\t❌ Invalid password" << std::endl;
		this->disconnected(user);}
    return password; 
}

std::string Server::nickCmd(User &user, std::vector<std::string> data)
{
    std::vector<std::string>::iterator d;
	std::string nickname = "";

    for (d = ++data.begin(); d != data.end(); d++){
    	nickname.append(*d);
    	if (d != data.end() - 1)
    		nickname.push_back(' ');}
    if (nickname.size() > 9) {
    	std::cout << "\nPlease tape '/set NICK <nickname>' cause it has more than 9 characters >"<< nickname << "<" <<  std::endl;
    	this->disconnected(user); return "";}
    else {
    	std::map<int, User>::iterator itv;
    	for (itv = users_list.begin(); itv != users_list.end(); itv++) {
    		if (nickname == itv->second.getNickName()) {
                std::cout << "\nYou have the same Nickname than aan other user, please change : >" << itv->second.getNickName() << "<" << std::endl;
                this->disconnected(user); return ""; }}}
    
    return nickname;
}

std::string Server::userCmd(std::vector<std::string> data)
{
	std::string username = "";
    std::vector<std::string>::iterator d;
	for (d = ++data.begin(); d != data.end(); d++){
		username.append(*d);
		if (d != data.end() - 1)
			username.push_back(' ');}

    return username;
}