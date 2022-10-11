#include "Server.hpp"

Server::Server(){
    std::cout << "Server Constructor called" << std::endl;
}

Server::~Server(){
    std::cout << "Server Destructor called" << std::endl;
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
}

void Server::connect()
{
    //poll
    pollfd poll_struct;
    poll_struct.fd = this->getNewSocket();
    poll_struct.events = POLLIN;
    this->getPollFds().clear();
    this->setPollFds(poll_struct);

    //ajouter une liste d'attente de socket de tous les User
    std::map<int, User>::iterator itu;
    for (itu = users_list.begin(); itu != users_list.end(); itu++)
    {
        poll_struct.fd = itu->first;
        this->setPollFds(poll_struct);
    }

    //wait for an event
    switch (poll(&(this->getPollFds()[0]), this->getPollFds().size(), 300)) // BLOCKS untill a fd is available + set max ping to -1 ??
	{
        case 0 : std::cout << "temp d'attente depasser" << std::endl; break ;
        case -1 : this->error("error: poll()"); break ;
	}
    
    int temp_fd;
    if (this->getPollFds()[0].revents == POLLIN) //si il y a des donnees en attente
    {
        // accept connection and get the fd
        temp_fd = accept(this->getServerFd(), (struct sockaddr *) &this->my_addr, &this->peer_addr_size);
        if (temp_fd == -1)
            this->error("error accept()");
        std::cout << "New user accepted with fd: " << temp_fd << std::endl;
    }
}



/* getters and setters */

//pollfds
void Server::setPollFds(pollfd poll_fd){
    this->poll_fds.push_back(poll_fd);
}
std::vector<pollfd> Server::getPollFds(){
    return (this->poll_fds);
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