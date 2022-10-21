#include "Channel.hpp"

Channel::Channel(std::string channel_name)
: channel_name(channel_name), topic("No topic"), nb_user(0) {}

Channel::~Channel() {}

std::string Channel::getChannelName() const { return this->channel_name; }
void Channel::setChannelName(std::string channel_name){ this->channel_name = channel_name; }

std::string Channel::getTopic() const { return this->topic; }
void Channel::setTopic(std::string topic) { this->topic = topic; }


int Channel::getNbUser() const
{
    return nb_user;
}

void Channel::setNbUser()
{
    this->nb_user++;
}

void Channel::delNbUser()
{
    //pout channel join
     this->nb_user--;

     // + channel list
}

bool Channel::getChannop() const { return channop; }
void Channel::setChannop(bool choice) { this->channop = choice; }