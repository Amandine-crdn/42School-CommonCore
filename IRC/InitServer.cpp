#	include "Server.hpp"

Server::Server(){
    std::cout << "Server Constructor called" << std::endl; }

Server::~Server(){
    std::cout << "Server Destructor called" << std::endl; }


/* ------ Methods ------*/


void Server::init_server(const char *port, const char *password)
{
    if (!atoi(port))
        this->error("error port");
    this->my_addr.sin_port = htons(atoi(port));
    this->my_addr.sin_family = AF_INET;
    this->my_addr.sin_addr.s_addr =  htonl(INADDR_ANY);
    this->setPassword(password);
    this->setServerFd(socket(AF_INET, SOCK_STREAM, 0));
    if (this->getServerFd() == -1)
        this->error("error socket()");
    if (bind(this->getServerFd(),(struct sockaddr *) &this->my_addr, sizeof(this->my_addr)) == -1)
        this->error("error bind()") ;
    if (listen(this->getServerFd(), 5) == -1) { // 5 : file d'attente
        this->error("error listen()"); }
	
	std::cout << "🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞   🌞" << std::endl;
    std::cout << std::endl;
	std::cout << "🌺 🌺 🌺 " << this->server_name << " starting on port " << atoi(port) << " with password " << this->getPassword() << " 🌺 🌺 🌺" << std::endl;
	std::cout << std::endl;
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
	for (std::map<int, User>::iterator itb = users_list.begin(); itb != users_list.end(); itb++){
		poll_struct.fd = itb->first;
		poll_fds.push_back(poll_struct);}
	if (poll(&(poll_fds[0]), poll_fds.size(), rand()) == -1)
        this->error("error: poll()");
	if (poll_fds[0].revents == POLLIN){
		temp_fd = accept(this->getServerFd(), (sockaddr *)&my_addr, &peer_addr_size); 
		users_list[temp_fd];
		if (temp_fd == -1)
		    this->error("error: accept()");
	std::cout << "\n🏡  New user accepted with fd: " << temp_fd << " 🏡\n" << std::endl;}
}

void Server::intercept()
{
   	char buffer[BUFFER_SIZE];
	int sizeRead;

	for (std::vector<pollfd>::iterator itb = ++poll_fds.begin(); itb != poll_fds.end(); itb++) { // skipping the master socket
		if (itb->revents == POLLIN) {
			sizeRead = recv(itb->fd, buffer, BUFFER_SIZE, 0);
			if (sizeRead == -1)
				this->error("error: recv()");
			else if (sizeRead == 0)
				this->disconnected(users_list[itb->fd]);
			else {
                users_list[itb->fd].setMsg(buffer, sizeRead);
				users_list[itb->fd].setFd(itb->fd);
				checker(users_list[itb->fd], users_list[itb->fd].getMsg());
				users_list[itb->fd].eraseMsg();
				 }}}
}   


/* ------ getters and setters ----- */

void Server::setPollFds(pollfd poll_fd){ this->poll_fds.push_back(poll_fd); }
std::vector<pollfd> Server::getPollFds() const { return this->poll_fds; }

void Server::setServerFd(int server_fd){ this->server_fd = server_fd;}
int Server::getServerFd() const { return this->server_fd; }

std::string  Server::getPassword() const { return this->password; }
void  Server::setPassword(std::string password) { this->password = password; }

//std::vector<Channel> Server::getChannelList() const { return this->channels_list; }
void Server::setChannelList(std::string new_channel) {
	 this->channels_list.push_back(Channel(new_channel));
	  } 