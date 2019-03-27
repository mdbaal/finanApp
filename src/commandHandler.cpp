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
		std::vector<std::string> s;// = allCommands();
		for (int j = 0; j < s.size();j++) {
			if (temp == s[j]) {
				return "default";
			}
		}
	}
	
	return temp;
}
//make call when program needs a value
float CommandHandler::getValueFromInput() {
	std::string temp = ""; 
	for (int i = stringIndex; i < inputString.length()+1; i++) {
		
		temp += inputString[i];
	}
	try {
		return std::stof(temp, NULL);
	}
	catch (std::exception e) {
		return 0;
	}
}