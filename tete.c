void Server::topicCmd(User &user, std::vector<std::string> data) {

	std::string topic;
	std::vector<std::string>::iterator itd;

	for (itd = data.begin(); itd != data.end(); itd++) {
		topic.append(*itd);
		if (itd != data.end() - 1)
			topic.push_back(' ');}

	std::vector<Channel>::iterator itc;
	for (itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {		
			if (itc->getChannelName() == data[1]) {
				itc->setTopic(topic);
			 	clientMessage(user, RPL_TOPIC, *itd, topic); }}
	
}



   else if (cmd.compare(RPL_TOPIC) == 0)
        result << cmd << channel_name << " :" << topic << DELIMITER;


	else if (data[0].compare("TOPIC") == 0)
			topicCmd(user, data);
		