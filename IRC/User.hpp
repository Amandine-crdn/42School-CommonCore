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

        void addBufferToMessages(char *buffer, size_t read_size);

        /* getters and setters */

        //username
        void setUserName(std::string user_name);
        std::string getUserName();
        //nickname
        void setNickName(std::string nick_name);
        std::string getNickName();
    
    private :

        std::string nick_name;
        std::string user_name;
};

#endif