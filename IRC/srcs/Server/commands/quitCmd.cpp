#include "../Server.hpp"

void Server::quitCmd(User &user)
{
	std::cout << "quitCmd" << std::endl;

	getpeername(user.getFd(), (struct sockaddr *)&_sin, (socklen_t *)&_sizeofsin);
	std::cout << "🌙 " << user.getNickName() << " was disconnected , ip " << inet_ntoa(_sin.sin_addr) << " , port " << ntohs(_sin.sin_port) << std::endl;
	close(user.getFd());
	this->clearUser(user);

	//this->eraseUser(user.getFd());
	//this->disconnected(user);
	//std::cout << "🌙 " << user.getNickName() << " was disconnected , ip " << inet_ntoa(my_addr.sin_addr) << " , port " << ntohs(my_addr.sin_port) << std::endl;
	//this->clientMessage(user, ERROR);
}