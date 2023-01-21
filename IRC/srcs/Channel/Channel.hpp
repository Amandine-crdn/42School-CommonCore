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

        bool getTopicProtec() const;
        void setTopicProtec(bool choice);

        bool getInvite() const;
        void setInvite(bool choice);
        
        std::string getTopic() const;
        void setTopic(std::string topic);

        int getNbUser() const;
        void setNbUser();
        void delNbUser();

        std::vector<User> users_list;
        std::vector<std::string> channops_list;

    private :

        Channel() ;
        std::string channel_name;
        std::string topic;
        int nb_user;
        bool topic_protection;
        bool invite;
};

#endif