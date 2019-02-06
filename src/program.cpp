#include "commandHandler.h"
#include "output.h"
#include "summary.h"
#include <map>
#include <fstream>
#include <string>
#include <iostream>

CommandHandler c = CommandHandler();
Output o = Output();

std::map<std::string, Summary*> summaries = std::map<std::string, Summary*>();
Summary* currentSummary = nullptr;

bool running = true;

void saveToFile() {
	if (currentSummary == nullptr) return;
	std::ofstream file;

	file.open(currentSummary->name + ".txt",std::iostream::trunc);

	if (file.fail()) {
		o.message("Can't open file");
		return;
	}

	file << currentSummary->name << std::endl;
	if (!currentSummary->getMap().empty()) {
		for (auto const& x : currentSummary->getMap()) {
			file << x.first << std::endl;
			file << x.second << std::endl;
		}
	}
	file.close();
}

void loadFromFile(std::string _s) {
	std::ifstream file;
	std::string str = "";
	std::string name = "";
	float f = 0;
	bool isfloat = false;
	Summary* s = new Summary();

	file.open(_s + ".txt");

	if (file.fail()) {
		o.message("Can't open file");
		return;
	}

	std::getline(file, s->name);

	while (std::getline(file, str)) {
		if (!isfloat) {
			name = str;
			isfloat = true;
		}
		else {
			f = std::stoi(str);
			isfloat = false;
		}

		if (!str.empty() && !isfloat) {
			s->add(name, f);
		}
	}
	currentSummary = s;
	s = nullptr;
	delete s;
}

void newSummary() {
	std::string str = c.getNameFromInput();

	if (summaries.size() > 0) {
		try {
			if (summaries.at(str) != nullptr) {
				o.message("This summary already exist");
				return;
			}
		}
		catch (const std::out_of_range& oor) {
			//
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
	
	loadFromFile(str);
	o.message("Loaded summary " + str);
}
void saveSummary() {
	
	std::string str = currentSummary->name;
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	o.message("saving..");
	saveToFile();
	//summaries.insert_or_assign(str, currentSummary);
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

