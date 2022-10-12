#include "Server.hpp"

Server::Server(){
    std::cout << "Server Constructor called" << std::endl; }

Server::~Server(){
    std::cout << "Server Destructor called" << std::endl; }

void Server::init_server(const char *port, const char *password)
{
	std::cout << "----- init_server ------" << std::endl;
    //check port
    if (!atoi(port))
        this->error("error port");
    this->my_addr.sin_port = htons(atoi(port));
    this->my_addr.sin_family = AF_INET;
    this->my_addr.sin_addr.s_addr =  htonl(INADDR_ANY);
    this->setPassword(password);
    //socket
    this->setServerFd(socket(AF_INET, SOCK_STREAM, 0));
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
	std::cout << "----- connect ------" << std::endl;
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
		// accept connection and get the fd to create new user
		temp_fd = accept(this->getServerFd(), (sockaddr *)&my_addr, &peer_addr_size); 
		users_list[temp_fd]; // create a user (without calling constructor twice)
		if (temp_fd == -1)
		    this->error("error: accept()");
		std::cout << "New user accepted with fd: " << temp_fd << std::endl;}
}

void Server::intercept()
{
	std::cout << "----- intercept ------" << std::endl;

   	char buffer[BUFFER_SIZE];
	int sizeRead;

	//Check if users's fd is sending new data
	for (std::vector<pollfd>::iterator itb = ++poll_fds.begin(); itb != poll_fds.end(); itb++) { // skipping the master socket
		//Users fd is ready, lets read 
		if (itb->revents == POLLIN) {
			sizeRead = recv(itb->fd, buffer, BUFFER_SIZE, 0);
			if (sizeRead == -1) // recv error
				this->error("error: recv()");
			else if (sizeRead == 0) // recv size = 0 : nothing to read anymore. User dosconnected.
				this->disconnected(users_list[itb->fd]);
			else { // read message protocole
                users_list[itb->fd].addMessages(buffer, sizeRead);
				users_list[itb->fd].setFd(itb->fd);
                std::cout << "User with fd[" << itb->fd << "] send : \n" << users_list[itb->fd].getMsg() << std::endl;
				dispatcher(users_list[itb->fd], users_list[itb->fd].getMsg()); }}}
}   

void Server::dispatcher(User &user, std::string message_protocole)
{
	if (user.getFirstConnexion() == true)
		this->firstConnexion(user, message_protocole);
	/*else
	{
	
	}*/
}

void Server::disconnected(User &user)
{
	getpeername(user.getFd(), (struct sockaddr *)&my_addr, (socklen_t *)&peer_addr_size);
	std::cout << "Host disconnected , ip " << inet_ntoa(my_addr.sin_addr) << " , port " << ntohs(my_addr.sin_port) << std::endl;
	close(user.getFd());
	users_list.erase(user.getFd());
}

void Server::firstConnexion(User &user, std::string message_protocole)
{
	std::string password;
	std::string nickname;
	std::size_t end;

	//PASS
	switch((message_protocole.find("PASS"))){
			case std::string::npos : {
				std::cout << "Please give a password" << std::endl;
				this->disconnected(user);
				return ; }
			default : {
				end = message_protocole.find("NICK") - 7 - message_protocole.find("PASS");
				password = message_protocole.substr(message_protocole.find("PASS") + 5, end);
				if (password == this->getPassword())
					std::cout << "great password" << std::endl;
				else {
					std::cout << "Invalid password" << std::endl;
					this->disconnected(user);
					return ; }}}
	//NICK
	end = message_protocole.find("USER") - 7 - message_protocole.find("NICK");
	nickname = message_protocole.substr(message_protocole.find("NICK") + 5, end);
	if (nickname.size() > 9) {
		std::cout << "Please tape '/set NICK <nickname>' cause it has more than 9 characters >"<< nickname << "<" <<  std::endl;
		this->disconnected(user); return ;}
	std::map<int, User>::iterator itv;
	for (itv = users_list.begin(); itv != users_list.end(); itv++) {
		if (nickname == itv->second.getNickName()) {
			std::cout << "You have the same Nickname than aan other user, please change : >" << itv->second.getNickName() << "<" << std::endl;
			this->disconnected(user); return ; }}
	user.setNickName(nickname); // bienvenue WLM MSG //<< "[!<user>@<host>]" << std::endl;
	std::cout << " : Welcome to the " << this->server_name << " Network," << nickname << std::endl;
	user.setFirstConnexion(false);
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

