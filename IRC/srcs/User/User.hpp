#ifndef USER_HPP
#define USER_HPP

#   include "../Server/Server.hpp"

class Channel;

class User {

    public :

        User();
        User(int fd);
        ~User();

        /* ----- methodes ----- */

        void addMessages(char *buffer, size_t read_size);
        std::string getFullClientIdentifier(void);

        bool isInChannel(std::string channel);
        void addChannel(std::string channel_name);

        void clearMsg();

        /* ----- getters and setters ----- */

        void setUserName(std::string user_name);
        std::string getUserName();

        void setRealName(std::string user_name);
        std::string getRealName();

        void setNickName(std::string nick_name);
        std::string getNickName();

        std::vector<std::string> getMsg();
        void setMsg(char *buffer, size_t read_size);

        bool getFirstConnexion() const;
        void setFirstConnexion(bool choice);

        int getFd() const;
        void setFd(int fd);

        bool getVisibility() const;
        void setVisibility(bool choice);

        bool getIRCOper() const;
        void setIRCOper(bool choice);

        bool getDelete() const;
        void setDelete(bool choice);

        bool getAllowPass() const;
        void setAllowPass(bool choice);

        bool getAllowCAP() const;
        void setAllowCAP(bool choice);

        bool getOpServer() const;
        void setOpServer(bool choice);
        

        std::vector<std::string> channelsJoin;

    
    private :

        std::string nick_name;
        std::string user_name;
        std::string real_name;
        bool first_connexion;
        int fd;
        std::vector<std::string> vector_message_protocole;
        //MODE +i
        bool visibility;
        //OPER
        bool IRCOperator;
        //quit
        bool toDelete;
        //pass
        bool allowPass;
        //cap
        bool allowCAP;
        //mode +O
        bool opServer;

        //liste de course des channels
};

#endif