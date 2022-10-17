#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#   include "Server.hpp"

class Channel {

    public :

       Channel(std::string channel_name);
       ~Channel() ;

        /* ----- getters and setters ----- */

        std::string getChannelName() const;
        void setChannelName(std::string channel_name);
        std::string getTopic() const;
        void setTopic(std::string topic);


    private :

        Channel() {};
        std::string channel_name;
        std::string topic;

};

#endif