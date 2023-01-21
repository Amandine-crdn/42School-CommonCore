#include "Channel.hpp"

Channel::Channel() {}

Channel::Channel(std::string channel_name)
: channel_name(channel_name), topic(""), nb_user(0), topic_protection(false), invite(false) {}

Channel::~Channel() {}

bool Channel::getTopicProtec() const { return this->topic_protection; }
void Channel::setTopicProtec(bool choice) { this->topic_protection = choice; }

bool Channel::getInvite() const { return this->invite; }
void Channel::setInvite(bool choice) { this->invite = choice; }

std::string Channel::getChannelName() const { return this->channel_name; }
void Channel::setChannelName(std::string channel_name){ this->channel_name = channel_name; }

std::string Channel::getTopic() const { return this->topic; }
void Channel::setTopic(std::string topic) { this->topic = topic; }

int Channel::getNbUser() const
{
    return this->nb_user;
}

void Channel::setNbUser()
{
    this->nb_user++;
}

void Channel::delNbUser()
{
     this->nb_user--;
}

