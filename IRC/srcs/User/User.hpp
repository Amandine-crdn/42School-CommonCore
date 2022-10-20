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
        bool isChannops(std::string channel);
        void toBeChannops(std::string channel);


        void clearMsg();

        /* ----- getters and setters ----- */

        void setUserName(std::string user_name);
        std::string getUserName();

        void setRealName(std::string user_name);
        std::string getRealName();

        void setNickName(std::string nick_name);
        std::string getNickName();

        std::vector<std::string> getMsg() /*const*/;
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

        bool getAllow() const;
        void setAllow(bool choice);


        std::vector<std::string> getChannops(void) const;//POUBELLE
        void setChannops(std::string channel); //POUBELLE


        //liste de course des channels
        std::vector<std::string> getChannelListByUser() const;//POUBELLE
        void setChannelListByUser(std::string new_channel);//POUBELLE


        std::vector<std::string> channops; //POUBELLE
        std::vector<std::string> channels_list_by_user; //POUBELLE
        

        std::vector<Channel> OPSforchans; // 2 1 dans chan a mettre + ici (en meme temps)
        std::vector<Channel> channelsJoin; 
    
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

        //liste de course des channels
        //std::vector<std::string> channels_list_by_user; //accesseur
};

#endif