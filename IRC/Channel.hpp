#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#   include "Server.hpp"

class Channel {

    public :

       Channel() {};
       Channel(std::string channel_name);
       ~Channel() {};

        /* ----- getters and setters ----- */

        std::string getChannelName();

        //que dans le constructeur
        //void setChannelName(std::string channel_name);

    private :

        std::string channel_name;


};

#endif