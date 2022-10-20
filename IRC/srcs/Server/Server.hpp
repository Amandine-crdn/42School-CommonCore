#ifndef SERVER_HPP
#define SERVER_HPP

#   define BUFFER_SIZE 4096
#   define DELIMITER "\r\n"

#   include <iostream>
#   include <sys/socket.h>
#   include <errno.h>
#   include <netinet/in.h>
#   include <unistd.h>
#   include <arpa/inet.h> 
#   include <vector>
#   include <cstring>
#   include <poll.h>
#   include <map>
#   include <fcntl.h>
#   include <ctime>
#   include <sstream>
#   include <cmath>

#   include "../Channel/Channel.hpp"
#   include "../User/User.hpp"
#   include "ClientMessage.hpp"

class User;
class Channel;

class Server {

    public :

        Server() : server_name("ft_irc") {}; // a mettre dans le cpp
        ~Server() {};

        /*------  methods Server ------ */

        void init_server(const char *port, const char *password);
        void error(std::string error);
        void connect();
        void intercept();
        void sendMessage();
        void clientMessage(User &user, std::string cmd, std::string channel_name = "", std::string topic = "");
        void checker();
        void dispatcher(User &user, std::string msg);

        /*for channels*/
        void eraseChannel(std::string channel_name);

        /*------- utils -------*/

        static std::vector<std::string> split(std::string msg, char delimiter);
        void notificationJoinChannel(User &user,std::string channel_name);
        void notificationsUsersInChannel(User &user, std::string channel_name);
        std::vector<User>::iterator beginVectorUser();
        std::vector<User>::iterator endVectorUser();
        std::vector<User>::iterator getUserByFd(int fd);
        void clearUser(User &user);
        void check_connexion(User &user);

        /*------ utils JOIN -------*/
        std::string getTopic(std::string channel);


        /*------- utils MODE-------*/


        bool channelExists(std::string channel);
        bool userExists(std::string nickname);


        /*------ getters and setters ----- */

        int getServerFd() const;
        void setServerFd(int server_fd);
        std::string getPassword() const;
        void setPassword(std::string password);
        std::vector<pollfd> getPollFds() const;
        void setPollFds(pollfd poll_fd);

        std::vector<Channel> getChannelList() const;
        void setChannelList(std::string new_channel);

        void setUser(int fd);

          /*------  methods CmdServer ------ */

        void passCmd(User &user, std::vector<std::string> data);
        void nickCmd(User &user, std::string msg, std::vector<std::string> data);
        void userCmd(User &user, std::string msg, std::vector<std::string> data);
        void quitCmd(User &user);
        void dieCmd(User &user, std::vector<std::string> data);
        void modeChannelCmd(User &user, std::vector<std::string> data);
        void modeUserCmd(User &user, std::vector<std::string> data);
        void pingCmd(User &user, std::vector<std::string> data);
        void joinCmd(User &user, std::vector<std::string> data);
        void privMsgCmd(User &user, std::string data);
        void operCmd(User &user, std::vector<std::string> data);
        void topicCmd(User &user, std::string msg, std::vector<std::string> data);
        void partCmd(User &user, std::vector<std::string> data);
        void adminCmd(User &user, std::vector<std::string> data);
        void invitCmd(User &user, std::vector<std::string> data);
        void squitCmd(User &user, std::vector<std::string> data);
        // void kickCmd(User &user, std::vector<std::string> data);
            

        private :

        int server_fd;
       
        std::string password;
        std::string server_name;
       
        std::vector<pollfd> poll_fds;
        std::vector<pollfd>		_pollfds;
        socklen_t				_sizeofsin;
	      sockaddr_in				_sin;

        std::map<int, User> users_list; //POUBELLE

        std::vector<User> utilisateurs_list;
        std::vector<Channel> channels_list;
};

#endif