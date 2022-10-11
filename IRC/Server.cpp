#include "Server.hpp"

Server::Server(){
    std::cout << "constructor called" << std::endl;
}

Server::~Server(){
    std::cout << "destructor called" << std::endl;
}

void Server::init_server()
{
    this->my_addr.sin_port = htons(6667);
    this->my_addr.sin_family = AF_INET;
    this->my_addr.sin_addr.s_addr =  htonl(INADDR_ANY);
    
    this->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server_fd == -1)
    {
        ENOTCONN ; //close and exit
    }
    else
        EISCONN ;

    //setsockopt optionnel

    if (bind(this->server_fd,(struct sockaddr *) &this->my_addr, sizeof(this->my_addr)) == -1)
    {
        EINVAL ;//close and exit
    }

    if (listen(this->server_fd, 1) == -1) // 1 : file d'attente
    {
        ECONNREFUSED ;
    }

    this->new_socket = accept(this->server_fd, (struct sockaddr *) &this->my_addr, &this->peer_addr_size);
    if (this->new_socket == -1)
    {
        ENFILE ;
    }
}

int Server::getNewSocket(){
    return (this->new_socket);
}

int Server::getServerFd(){
    return (this->server_fd);
}