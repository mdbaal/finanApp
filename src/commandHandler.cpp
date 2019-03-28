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
	if (argumentList.size() < 1) return "";
	return argumentList[0];
}
//make call when program needs a name
std::string CommandHandler::argument1() {
	if (argumentList.size() < 2) return "";
	return argumentList[1];
}
//make call when program needs a value
std::string CommandHandler::argument2() {

	if (argumentList.size() < 3) return "";
	return	argumentList[2], NULL;

}