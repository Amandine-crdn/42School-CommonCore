#include "Channel.hpp"

Channel::Channel(std::string channel_name) : channel_name(channel_name), topic("No topic") {}

Channel::~Channel() {}

std::string Channel::getChannelName() const { return this->channel_name; }
void Channel::setChannelName(std::string channel_name){ this->channel_name = channel_name; }

std::string Channel::getTopic() const { return this->topic; }
void Channel::setTopic(std::string topic) { this->topic = topic; }