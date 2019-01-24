#include "commandHandler.h"

CommandHandler::CommandHandler(){

}

CommandHandler::~CommandHandler(){


}
void CommandHandler::getInput() {
	inputString = "";
	inputString = input.readline();
}
//make call from program to see what to do.
std::string CommandHandler::getCommandFromInput() {
	stringIndex = 0;
	std::string temp = "";
	for (int i = stringIndex; i < inputString.length();i++) {
		if (inputString[i] == ' ') {
			stringIndex = i+1;
			return temp;
		}
		else {
			temp += inputString[i];
		}
	}
	return temp;
}
//make call when program needs a name
std::string CommandHandler::getNameFromInput() {
	std::string temp = "";
	for (int i = stringIndex; i < inputString.length(); i++) {
		if (inputString[i] == ' ') {
			stringIndex = i+1;
			return temp;
		}
		else {
			temp += inputString[i];
		}
	}
	return temp;
}
//make call when program needs a value
float CommandHandler::getValueFromInput() {
	std::string temp = ""; 
	for (int i = stringIndex; i < inputString.length(); i++) {
		if (inputString[i] == ' ') {
			stringIndex = i+1;
			return std::stof(temp,NULL);
			
		}
		else if (inputString[i] == inputString.back()){
			stringIndex = i + 1;
			temp += inputString[i];
			return std::stof(temp, NULL);
		}
		else {
			temp += inputString[i];
		}
	}
	return 0;
}