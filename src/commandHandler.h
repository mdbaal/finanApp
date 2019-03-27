#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "commands.h"
#include <vector>
#include "input.h"
#include <string>
#include <stdlib.h> 


class CommandHandler{
public:
	CommandHandler();
	virtual ~CommandHandler();
	void getInput();
	std::string getCommandFromInput();
	std::string getNameFromInput();
	float getValueFromInput();

private:
	Input input =  Input();
	std::string inputString = "";

	int stringIndex = 0;
};

#endif //COMMANDHANDLER_H