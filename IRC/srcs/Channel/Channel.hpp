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

        int getNbUser() const;
        void setNbUser();
        void delNbUser();

        bool getChannop() const;
        void setChannop(bool choice);

        std::vector<User> channops; // POUBELLE
        std::vector<std::string> users_list; // au lieu de setnb etc, faire size de ce vector +++++


    private :

        Channel() {};
        std::string channel_name;
        std::string topic;
        int nb_user;
        bool channop;


};

#endif