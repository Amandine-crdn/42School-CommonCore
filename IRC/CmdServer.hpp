#ifndef CMDSERVER_HPP
#define CMDSERVER_HPP

#   include "Server.hpp"

class CmdServer : public Server {

    public :

       CmdServer() {};
       ~CmdServer() {} ;

    /*------  methods CmdServer ------ */

    std::string passCmd(User &user, std::vector<std::string> data, bool first);
    std::string nickCmd(User &user, std::string msg, bool first);
    std::string userCmd(User &user, std::string msg, bool first);
    void modeCmd(User &user, std::vector<std::string> data);
    void quitCmd(User &user);
    void pingCmd(User &user, std::vector<std::string> data);
    void joinCmd(User &user, std::vector<std::string> data);
    void privMsgCmd(User &user, std::string data);
    void operCmd(User &user, std::vector<std::string> data);
    void topicCmd(User &user, std::string msg, std::vector<std::string> data);
    void partCmd(User &user, std::vector<std::string> data);
    void dieCmd(User &user, std::vector<std::string> data);
    void adminCmd(User &user, std::vector<std::string> data);
    void invitCmd(User &user, std::vector<std::string> data);
   // void kickCmd(User &user, std::vector<std::string> data);
};

#endif