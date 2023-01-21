#   include "Server.hpp"

Server::Server() : server_fd(0), server_name("ft_irc"), host("localhost")
{}
Server::~Server()
{}

/* ------ getters and setters ----- */

void Server::setServerFd(int server_fd){ this->server_fd = server_fd;}
int Server::getServerFd() const { return this->server_fd; }

std::string  Server::getPassword() const { return this->password; }
void  Server::setPassword(std::string password) { this->password = password; }


