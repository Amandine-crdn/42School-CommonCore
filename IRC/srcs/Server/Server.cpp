#   include "Server.hpp"

Server::Server() : server_name("ft_irc")
{}
Server::~Server()
{}

/* ------ getters and setters ----- */

void Server::setPollFds(pollfd poll_fd){ this->poll_fds.push_back(poll_fd); }
std::vector<pollfd> Server::getPollFds() const { return this->poll_fds; }

void Server::setServerFd(int server_fd){ this->server_fd = server_fd;}
int Server::getServerFd() const { return this->server_fd; }

std::string  Server::getPassword() const { return this->password; }
void  Server::setPassword(std::string password) { this->password = password; }


