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
		// accept connection and get the fd to create new user
		temp_fd = accept(this->getServerFd(), (sockaddr *)&my_addr, &peer_addr_size); 
		users_list[temp_fd]; // create a user (without calling constructor twice)
		if (temp_fd == -1)
		    this->error("error: accept()");
		std::cout << "New user accepted with fd: " << temp_fd << std::endl;
	}
}

void Server::intercept()
{
   	char buffer[BUFFER_SIZE];
	int sizeRead;

	/*Check if users's fd is sending new data*/
	for (std::vector<pollfd>::iterator itb = ++poll_fds.begin(); itb != poll_fds.end(); itb++) // skipping the master socket
	{
		/*Users fd is ready, lets read it on one buffer.*/
		if (itb->revents == POLLIN)
		{
			for (int i = 0; i < BUFFER_SIZE; i++)
		    buffer[i] = '\0';

			sizeRead = recv(itb->fd, buffer, BUFFER_SIZE, 0);
			if (sizeRead == -1) // recv error
				this->error("error: recv()");
			else if (sizeRead == 0) // recv size = 0 : nothing to read anymore. User dosconnected.
			{
				getpeername(itb->fd, (struct sockaddr *)&my_addr, (socklen_t *)&peer_addr_size);
				std::cout << "Host disconnected , ip " << inet_ntoa(my_addr.sin_addr) << " , port " << ntohs(my_addr.sin_port) << std::endl;
				close(itb->fd);
				users_list.erase(itb->fd);
				std::cout << "host closed and erased" << std::endl;
			}
			else // read message protocole
			{
                users_list[itb->fd].addMessages(buffer, sizeRead);
                std::cout << "User with fd[" << itb->fd << "] send : \n" << users_list[itb->fd].getMsg() << std::endl;
            }
		}
	}
}   

/* getters and setters */

//pollfds
void Server::setPollFds(pollfd poll_fd){ this->poll_fds.push_back(poll_fd); }
std::vector<pollfd> Server::getPollFds() const { return this->poll_fds; }

//serverfd
void Server::setServerFd(int server_fd){ this->server_fd = server_fd;}
int Server::getServerFd() const { return this->server_fd; }

//password
std::string  Server::getPassword() const { return this->password; }
void  Server::setPassword(std::string password) { this->password = password; }

