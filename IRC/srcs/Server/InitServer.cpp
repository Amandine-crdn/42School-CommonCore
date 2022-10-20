#	include "Server.hpp"


/* ------ Methods ------*/

void Server::init_server(const char *port, const char *password)
{
	int enable = 1;
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(atoi(port));
	_sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (_sin.sin_port == 0)
		error("invalid port");
	_sizeofsin = sizeof(_sin);
    if (!atoi(port)) {
        this->error("error port"); }
    this->setPassword(password);
    this->setServerFd(socket(AF_INET, SOCK_STREAM, 0));
    if (this->getServerFd() == -1) {
        this->error("error socket()"); }
	if (setsockopt(this->getServerFd(), SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(enable)) == -1) {
		this->error("setsockopt()"); }
	if (fcntl(this->getServerFd(), F_SETFL, O_NONBLOCK) == -1) {
		this->error("fcntl()"); }
    if (bind(getServerFd(), (sockaddr *)&_sin, _sizeofsin) == -1)
			error("bind()");
    if (listen(this->getServerFd(), 5) == -1) { // 5 : file d'attente
        this->error("error listen()"); }
	
	std::cout << "🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞" << std::endl;
    std::cout << std::endl;
	std::cout << "🌺 🌺 🌺 " << this->server_name << " starting on port " << atoi(port) << " with password " << this->getPassword() << " 🌺 🌺 🌺" << std::endl;
	std::cout << std::endl;
}

void Server::connect()
{
	pollfd tempPollFd;

	_pollfds.clear();

	tempPollFd.fd = getServerFd();
	tempPollFd.events = POLLIN;
	_pollfds.push_back(tempPollFd);

	for (std::vector<User>::iterator it = utilisateurs_list.begin(); it != utilisateurs_list.end(); it++)
	{
		tempPollFd.fd = it->getFd();
		_pollfds.push_back(tempPollFd);
	}

	if (poll(&(_pollfds[0]), _pollfds.size(), 300000) == -1)
		error("poll()");

	int tempFd;

	if (_pollfds[0].revents == POLLIN)
	{
		tempFd = accept(getServerFd(), (sockaddr *)&_sin, &_sizeofsin);
		if (tempFd == -1)
			error("accept()");
		utilisateurs_list.push_back(User(tempFd));
		std::cout << "\n🏡  New user accepted with fd: " << tempFd << " 🏡\n" << std::endl;
	}
}

void Server::intercept()
{
   	char buffer[BUFFER_SIZE];
	int sizeRead;
	
	for (std::vector<pollfd>::iterator itb = ++_pollfds.begin(), ite = _pollfds.end(); itb != ite; itb++) // skipping the master fd socket
	{
		if (itb->revents == POLLIN)
		{
			for (int i = 0; i < BUFFER_SIZE; i++)
			buffer[i] = '\0';

			sizeRead = recv(itb->fd, buffer, BUFFER_SIZE, 0);

			if (sizeRead == -1)
				this->error("error: recv()");

			else if (sizeRead == 0)
			{ 
				getpeername(itb->fd, (struct sockaddr *)&_sin, (socklen_t *)&_sizeofsin);
				std::cout << "Host disconnected , ip " << inet_ntoa(_sin.sin_addr) << " , port " << ntohs(_sin.sin_port) << std::endl;
				close(itb->fd);
				this->clearUser(*(this->getUserByFd(itb->fd)));
				std::cout << "host closed and user erased" << std::endl;
				
				/*close(this->getServerFd()); // closing the connected socket
				shutdown(this->getServerFd(), SHUT_RDWR); // closing the listening socket
				std::cout << "🌙 🌙 closing with die command 🌙 🌙" << std::endl;*/
				
				//this->disconnected(users_list[itb->fd]);
			}
			else
                this->getUserByFd(itb->fd)->setMsg(buffer, sizeRead);
		}
	}
}   

/* ------ getters and setters ----- */

void Server::setPollFds(pollfd poll_fd){ this->poll_fds.push_back(poll_fd); }
std::vector<pollfd> Server::getPollFds() const { return this->poll_fds; }

void Server::setServerFd(int server_fd){ this->server_fd = server_fd;}
int Server::getServerFd() const { return this->server_fd; }

std::string  Server::getPassword() const { return this->password; }
void  Server::setPassword(std::string password) { this->password = password; }

std::vector<Channel> Server::getChannelList() const { return this->channels_list; } 
void Server::setChannelList(std::string new_channel) { this->channels_list.push_back(Channel(new_channel)); } 
