#ifndef CMDSERVER_HPP
#define CMDSERVER_HPP

#   include "Server.hpp"

class CmdServer : public Server {

    public :

       CmdServer() {};
       ~CmdServer() {} ;

    /*------  methods CmdServer ------ */

    std::string passCmd(User &user, std::vector<std::string> data, bool first);
    std::string nickCmd(User &user, std::vector<std::string> data, bool first);
    std::string userCmd(User &user,std::vector<std::string> data, bool first);
    void modeCmd(User &user, std::vector<std::string> data);
    void quitCmd(User &user, std::vector<std::string> data);
    void pingCmd(User &user, std::vector<std::string> data);
    void joinCmd(User &user, std::vector<std::string> data);
    void privMsgCmd(User &user, std::string msg);
    void operCmd(User &user, std::vector<std::string> data);

};

#endif