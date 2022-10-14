#ifndef USER_HPP
#define USER_HPP

#   include "Server.hpp"

class User {

    public :

        User();
        ~User() {};

        /* ----- methodes ----- */

        void addMessages(char *buffer, size_t read_size);
        void eraseMsg();

        /* ----- getters and setters ----- */

        void setUserName(std::string user_name);
        std::string getUserName();
        void setNickName(std::string nick_name);
        std::string getNickName();
        std::vector<std::string> getMsg() const;
        void setMsg(char *buffer, size_t read_size);
        bool getFirstConnexion() const;
        void setFirstConnexion(bool choice);
        int getFd() const;
        void setFd(int fd);
        bool getVisibility() const;
        void setVisibility(bool choice);
        bool getIRCOper() const;
        void setIRCOper(bool choice);

        //liste de course des channels
        ///std::map<bool, std::string> getChannelListByUser() const;
        void setChannelListByUser(bool admin, std::string new_channel);

        std::map<bool, std::string> channels_list_by_user; //accesseur
    
    private :

        std::string nick_name;
        std::string user_name;
        bool first_connexion;
        int fd;
        std::vector<std::string> vector_message_protocole;
        //MODE +i
        bool visibility;
        bool IRCOperator;
        //liste de course des channels
        //std::vector<std::string> channels_list_by_user; //accesseur
};

#endif