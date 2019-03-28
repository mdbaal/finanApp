#include "commandHandler.h"
#include "output.h"
#include "summary.h"
#include <map>
#include "filehandler.h"
#include <string>

CommandHandler c;
Filehandler f = Filehandler();
Output o = Output();

std::map<std::string, Summary*> summaries = std::map<std::string, Summary*>();
Summary* currentSummary = nullptr;

bool running = true;

void newSummary() {
	std::string str = c.argument1();
	if (str.empty()) {
		o.message("Name is empty, creation failed");
	}
		try {
			if (summaries.at(str) != nullptr) {
				o.message("This summary already exist");
				return;
			}
		}
		catch (const std::out_of_range& oor) {
			Summary* s = new Summary();
			summaries.insert_or_assign(str, s);
			currentSummary = s;
			s->name = str;
			o.message("Created new summary " + str);
		}
}
void deleteSummary() {
	std::string str = c.argument1();
	if (summaries.count(str) == 0){
		o.message("Summary doesn't exist"); 
		return;
	}
	if (f.deleteFile(str)) {
		Summary* s = summaries.at(str);
		summaries.erase(str);
		s = nullptr;
		delete s;
		delete currentSummary;
		currentSummary = nullptr;
		o.message("Deleted " + str);
		
	}
	else {
		Summary* s = summaries.at(str);
		summaries.erase(str);
		s = nullptr;
		delete s;
		delete currentSummary;
		currentSummary = nullptr;
		o.message("Deleted " + str);
	}
}
void loadSummary() {
	std::string str = c.argument1();
	if (summaries.count(str) > 0) {
		currentSummary = summaries.at(str);
		o.message("Loaded: " + str,4);
	}
	else {
		Summary* s = f.loadFromFile(str);
		if (s == nullptr) {
			o.message("Summary doesn't exist, create a new one using 'new'");
			return;
		}
		else {
			summaries.insert_or_assign(str, s);
			currentSummary = summaries.at(str);
			o.message("Loaded: " + str,4);
		}
	}
}
void saveSummary() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	std::string str = currentSummary->name;
	o.message("Saving..");
	f.saveToFile(currentSummary);
	summaries.insert_or_assign(str, currentSummary);
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
	std::string str = c.argument1();
	if (str.empty() || str == "") {
		o.message("Missing name, adding entry failed");
	}
	float f = c.argument2();
	currentSummary->add(str, f);
	o.message("Added " + str + " - " + std::to_string(f) + " to summary " + currentSummary->name);
}
void removeFromSummary() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	std::string str = c.argument1();
	float f = currentSummary->getValue(str);
	currentSummary->remove(str);
	o.message("Removed " + str + " - " + std::to_string(f) + " from summary " + currentSummary->name);
}
void quit() {
	o.message("Goodbye");
	running = false;
}

void getAction() {
	std::string str = c.command();
	if (str == NEW) {
		newSummary();
		saveSummary();
		return;
	}
	else if (str == DEL) {
		deleteSummary();
		return;
	}
	else if (str == LOAD) {
		loadSummary();
		return;
	}
	else if (str == SAVE) {
		saveSummary();
		return;
	}
	else if (str == VIEW) {
		saveSummary();
		viewSummary();
		return;
	}
	else if (str == ADD) {
		addToSummary();
		return;
	}
	else if (str == REMOVE) {
		removeFromSummary();
		return;
	}
	else if (str == QUIT || str == EXIT) {
		quit();
		return;
	}
	else if (str == HELP) {
		o.printHelp();
		return;
	}
	o.message("Wrong command entered, try again");
}
void loadToSummaries() {
	
}
void clean() {
	summaries.clear();
	o.message("Cleaned pointers");
}


int main() {
	//program loop
	while (running) {
		o.message("Enter a command");
		c.getInput();
		getAction();
	}
	saveSummary();
	clean();
	return 0;
}

