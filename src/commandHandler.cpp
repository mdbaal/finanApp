#include "commandHandler.h"

CommandHandler::CommandHandler(){

}

CommandHandler::~CommandHandler(){


}
void CommandHandler::getInput() {
	inputString.clear();
	inputString.str(input.readline());
	getArguments();
}
void CommandHandler::getArguments() {
	std::string temp;
	argumentList.clear();
	while (std::getline(inputString, temp, ' ')) {
		argumentList.push_back(temp);
	};
}
std::vector<std::string> CommandHandler::arguments() {
	return argumentList;
}


//make call from program to see what to do.
std::string CommandHandler::command() {
	return argumentList[0];
}
//make call when program needs a name
std::string CommandHandler::argument1() {
	return argumentList[1];
}
//make call when program needs a value
float CommandHandler::argument2() {
	try {
		return std::stof(argumentList[2], NULL);
	}
	catch (std::exception e) {
		return 0;
	}
}