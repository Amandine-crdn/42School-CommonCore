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
    if (listen(this->getServerFd(), 5) == -1) // 5 : file d'attente
        this->error("error listen()"); //getter servername need
    std::cout << ">" << this->server_name << "< starting on port >" << atoi(port) << "< with password >" << this->getPassword() << "<" << std::endl;
}

void Server::connect()
{
    int temp_fd;
	pollfd poll_struct;
    srand(time(0));
	poll_fds.clear();
	poll_struct.fd = this->getServerFd();
	poll_struct.events = POLLIN;
	poll_fds.push_back(poll_struct);

	for (std::map<int, User>::iterator itb = users_list.begin(); itb != users_list.end(); itb++)
	{
		poll_struct.fd = itb->first;
		poll_fds.push_back(poll_struct);
	}

	if (poll(&(poll_fds[0]), poll_fds.size(), rand()) == -1)
        this->error("error: poll()");

	if (poll_fds[0].revents == POLLIN)
	{
		/*Accepting and creating new user*/
		temp_fd = accept(this->getServerFd(), (sockaddr *)&my_addr, &peer_addr_size); // accept connection and get the fd
		users_list[temp_fd];												// create a user (without calling constructor twice)
		if (temp_fd == -1)
		    this->error("error: accept()");
		std::cout << "New user accepted with fd: " << temp_fd << std::endl;
	}
}
/*
void Server::intercept()
{
    char buffer[BUFFER_SIZE];

    std::vector<pollfd>::iterator itp;
    for (itp = this->getPollFds().begin() + 1; itp != this->getPollFds().end(); itp++)
    {
        int read_size;
        //pret a lire message du User
        if (itp->revents == POLLIN)
        {
            //buffer.clear();
            read_size = recv(itp->fd, buffer, BUFFER_SIZE, 0);
            std::cout << read_size << std::endl;
            switch(read_size)
            {
                case -1 : this->error("error recv()"); break;
                case 0 : // user: /exit => User dosconnected.
                {
                    getpeername(itp->fd, (struct sockaddr *) &this->my_addr, (socklen_t *)&peer_addr_size);
                    std::cout << "Host disconnected , ip " << inet_ntoa(my_addr.sin_addr) << " , port " << ntohs(my_addr.sin_port) << std::endl;
                    close(itp->fd);
                    this->users_list.erase(itp->fd);
                    std::cout << "host closed and erased" << std::endl;
                }; break; 
                default :
                {
                    this->users_list[itp->fd].addBufferToMessages(buffer, read_size);
                    std::cout << "COucou" << std::endl; break;
                }
            }
        }
    }
}   */

/* getters and setters */

//pollfds
void Server::setPollFds(pollfd poll_fd){
    this->poll_fds.push_back(poll_fd);
}
std::vector<pollfd> Server::getPollFds() const {
    return (this->poll_fds);
}

//serverfd
void Server::setServerFd(int server_fd){ this->server_fd = server_fd;}
int Server::getServerFd() const {return (this->server_fd);}

//password
std::string  Server::getPassword() const {return (this->password);}
void  Server::setPassword(std::string password){this->password = password;}