#include "Server.hpp"

void Server::quitCmd(User &user) 
{
	this->clientMessage(user, ERROR);
	getpeername(user.getFd(), (struct sockaddr *)&my_addr, (socklen_t *)&peer_addr_size);
	std::cout << "🌙 " << user.getNickName() << " was disconnected , ip " << inet_ntoa(my_addr.sin_addr) << " , port " << ntohs(my_addr.sin_port) << std::endl;
	this->eraseUser(user.getFd());
}