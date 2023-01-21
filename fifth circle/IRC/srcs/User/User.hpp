#ifndef USER_HPP
#define USER_HPP

#   include "../Server/Server.hpp"

class Channel;

class User {

    public :

        User(int fd);
        ~User();

        /* ----- methodes ----- */

        void addMessages(char *buffer, size_t read_size);
        void clearMsg();

        /* ----- getters and setters ----- */

        void setUserName(std::string user_name);
        std::string getUserName();

        void setRealName(std::string user_name);
        std::string getRealName();

        void setMask(std::string params);
        std::string getMask();

        void setNickName(std::string nick_name);
        std::string getNickName();

        std::vector<std::string> getMsg();
        void setMsg(char *buffer, size_t read_size);

        bool getFirstConnexion() const;
        void setFirstConnexion(bool choice);

        int getFd() const;

        bool getVisibility() const;
        void setVisibility(bool choice);

        bool getIRCOper() const;
        void setIRCOper(bool choice);

        bool getAllowPass() const;
        void setAllowPass(bool choice);

        bool getAllowCAP() const;
        void setAllowCAP(bool choice);
                
        bool getAllowNick() const;
        void setAllowNick(bool choice);
                

    private :

        User();
        
        std::string nick_name;
        std::string user_name;
        std::string real_name;
        std::string mask;
        
        bool first_connexion;
        int fd;
        
        std::vector<std::string> vector_message_protocole;
        
        bool visibility;
        bool IRCOperator;
        bool allowPass;
        bool allowCAP;
        bool allowNick;
 

};

#endif