#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#   include "../Server/Server.hpp"

class User;

class Channel {

    public :

       Channel(std::string channel_name);
       ~Channel() ;

        /* ----- getters and setters ----- */

        std::string getChannelName() const;
        void setChannelName(std::string channel_name);
        
        std::string getTopic() const;
        void setTopic(std::string topic);

        std::vector<User> channops;


    private :

        Channel() {};
        std::string channel_name;
        std::string topic;


};

#endif