#include "../Server.hpp"

void Server::quitCmd(User &user)
{
	std::cout << "quitCmd" << std::endl;

	//getpeername(user.getFd(), (struct sockaddr *)&_sin, (socklen_t *)&_sizeofsin);
	//std::cout << "🌙 " << user.getNickName() << " was disconnected , ip " << inet_ntoa(_sin.sin_addr) << " , port " << ntohs(_sin.sin_port) << std::endl;
	
	user.setDelete(true); //POUBELLE
}