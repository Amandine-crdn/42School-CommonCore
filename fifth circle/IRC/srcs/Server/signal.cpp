#include "Server.hpp"

extern bool run;

// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
	(void)signum;
	std::cout << "🌙 🌙 END of Program Signal Caught 🌙 🌙" << std::endl;
	run = false;
}
