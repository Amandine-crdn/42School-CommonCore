#include "Server.hpp"

Server::Server(){
    std::cout << "constructor called" << std::endl;
}

Server::~Server(){
    std::cout << "destructor called" << std::endl;
}

void Server::init_server(const char *port, const char *password)
{
    //check port
    if (!atoi(port))
        this->error("error port");
    this->my_addr.sin_port = htons(atoi(port));
    this->my_addr.sin_family = AF_INET;
    this->my_addr.sin_addr.s_addr =  htonl(INADDR_ANY);
    this->setPassword(password);
    //socket
    this->setServerFd(socket(AF_INET, SOCK_STREAM, 0)); //setsockopt optionnel
    if (this->getServerFd() == -1)
        this->error("error socket()");
    //bind
    if (bind(this->getServerFd(),(struct sockaddr *) &this->my_addr, sizeof(this->my_addr)) == -1)
        this->error("error bind()") ;
    //listen
    if (listen(this->getServerFd(), 1) == -1) // 1 : file d'attente
        this->error("error listen()");
    //accept
    this->setNewSocket(accept(this->getServerFd(), (struct sockaddr *) &this->my_addr, &this->peer_addr_size));
    if (this->getNewSocket() == -1)
        this->error("error accept()");
}

//serverfd
void Server::setServerFd(int server_fd){ this->server_fd = server_fd;}
int Server::getServerFd(){return (this->server_fd);}

//newsocket
int Server::getNewSocket(){return (this->new_socket);}
void Server::setNewSocket(int new_socket){this->new_socket = new_socket;}

//password
std::string  Server::getPassword(){return (this->password);}
void  Server::setPassword(std::string password){this->password = password;}