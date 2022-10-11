#ifndef USER_HPP
#define USER_HPP

#define BUFFER_SIZE 4096
#define DELIMITER "\r\n"

#include <iostream>
#include <vector>
#include <cstring>
#include <poll.h>


class User {

    public :

        User();
        ~User();

        /* methodes */

        void addMessages(char *buffer, size_t read_size);

        /* getters and setters */

        //username
        void setUserName(std::string user_name);
        std::string getUserName();
        //nickname
        void setNickName(std::string nick_name);
        std::string getNickName();
        //msg protocole
        std::string getMsg() const;
        void setMsg(std::string msg);
    
    private :

        std::string nick_name;
        std::string user_name;
        //message protocole
        std::string message_protocole;
};

#endif