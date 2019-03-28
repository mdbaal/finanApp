#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <string>
#include <stdlib.h> 
#include <iostream>
#include <sstream>
#include "commands.h"
#include <vector>
#include "input.h"

class CommandHandler{
public:
	CommandHandler();
	virtual ~CommandHandler();
	void getInput();
	std::vector<std::string> arguments();
	std::string command();
	std::string argument1();
	std::string argument2();

private:
	Input input =  Input();
	std::istringstream inputString;
	std::vector<std::string> argumentList = std::vector<std::string>();
	void getArguments();
};

#endif //COMMANDHANDLER_H