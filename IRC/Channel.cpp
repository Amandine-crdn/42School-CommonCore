#include "Channel.hpp"

Channel::Channel(std::string channel_name) : channel_name(channel_name) {}

Channel::~Channel() {}

std::string Channel::getChannelName() { return this->channel_name; }
//que dans le constructeur
//void Channel::setChannelName(std::string channel_name){ this->channel_name = channel_name; }

