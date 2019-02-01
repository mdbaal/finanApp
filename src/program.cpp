#include "commandHandler.h"
#include "output.h"
#include "summary.h"
#include <map>
#include <string>
#include <iostream>

CommandHandler c = CommandHandler();
Output o = Output();

std::map<std::string, Summary*> summaries = std::map<std::string, Summary*>();
Summary* currentSummary = nullptr;

bool running = true;


void newSummary() {
	std::string str = c.getNameFromInput();

	if (summaries.size() > 0) {
		if (summaries.at(str) != nullptr) {
			o.message("This summary already exist");
			return;
		}
	}

	Summary* s =  new Summary();
	summaries.insert_or_assign(str,s);
	currentSummary = s;
	s->name = str;
	o.message("Created new summary " + str);
}
void deleteSummary() {
	std::string str = c.getNameFromInput();
	if (summaries.count(str) == 0){
		o.message("Summary doesn't exist"); 
		return;
	}
	Summary* s = summaries.at(str);
	summaries.erase(str);
	delete s;
	s = nullptr;
	o.message("Removed " + str);
}
void loadSummary() {
	std::string str = c.getNameFromInput();
	if (summaries.count(str) == 0) {
		o.message("Summary doesn't exist");
		return;
	}
	currentSummary = summaries.at(str);
	o.message("Loaded summary " + str);
}
void saveSummary() {
	
	std::string str = currentSummary->name;
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	o.message("saving..");
	summaries.insert_or_assign(str, currentSummary);
	o.message("Saved");
}
void viewSummary() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	o.message("Viewing summary " + currentSummary->name);
	o.drawSummary(currentSummary);
}

void addToSummary() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	std::string str = c.getNameFromInput();
	float f = c.getValueFromInput();
	currentSummary->add(str, f);
	o.message("Added " + str + " - " + std::to_string(f) + " to summary " + currentSummary->name);
}
void removeFromSummary() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	std::string str = c.getNameFromInput();
	float f = currentSummary->getValue(str);
	currentSummary->remove(str);
	o.message("Removed " + str + " - " + std::to_string(f) + " from summary " + currentSummary->name);
}
void quit() {
	o.message("Goodbye");
	running = false;
}

void getAction() {
	std::string str = c.getCommandFromInput();
	if (str == NEW) {
		newSummary();
	}
	else if (str == DEL) {
		deleteSummary();
	}
	else if (str == LOAD) {
		loadSummary();
	}
	else if (str == SAVE) {
		saveSummary();
	}
	else if (str == VIEW) {
		viewSummary();
	}
	else if (str == ADD) {
		addToSummary();
	}
	else if (str == REMOVE) {
		removeFromSummary();
	}
	else if (str == QUIT || str == EXIT) {
		quit();
	}
	else if (str == HELP) {
		o.printHelp();
	}
}

int main() {

	//program loop
	while (running) {
		o.message("Enter a command");
		c.getInput();
		getAction();
	}
	saveSummary();
	return 0;
}

