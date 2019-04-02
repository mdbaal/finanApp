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
		o.message("Loaded: " + str,o.blue);
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
			o.message("Loaded: " + str,o.blue);
		}
	}
}
void saveSummary() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	std::string str = currentSummary->name;
	f.saveToFile(currentSummary);
	summaries.insert_or_assign(str, currentSummary);
	o.message("Saved");
}
void copySummary() {
	if (summaries.count(c.argument1()) == 0) {
		o.message("Summary doens't exist, copy failed");
		return;
	}
	Summary* original = summaries.at(c.argument1());
	Summary* copy = new Summary();
	copy->name = original->name + '1';
	copy->setMap(original->getMap());
	summaries.insert_or_assign(copy->name, copy);
	currentSummary = copy;
	saveSummary();
	o.message("Copied " + original->name + " with name " + copy->name);

}
void renameSummary() {
	if (summaries.count(c.argument1()) == 0) {
		o.message("Summary doens't exist, rename failed");
		return;
	}
	Summary* old = summaries.at(c.argument1());
	Summary* renamed = new Summary();
	renamed->name = c.argument2();
	renamed->setMap(old->getMap());
	renamed->name = c.argument2();
	summaries.insert_or_assign(renamed->name, renamed);
	deleteSummary();
	currentSummary = renamed;
	o.message("Renamed " + c.argument1() + " to " + c.argument2());
}
void viewSummary() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	o.message("Viewing summary " + currentSummary->name,o.blue);
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
		return;
	}
	std::string str2 = c.argument2();
	if (str2.empty() || str2 == "") {
		o.message("Missing value, adding entry failed");
		return;
	}
	str2.resize(4);
	float f = std::stof(str2,NULL);
	currentSummary->add(str, f);
	o.message("Added " + str + " - " + str2 + " to summary " + currentSummary->name);
}
void removeFromSummary() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	std::string str = c.argument1();
	if (currentSummary->getMap().count(str) == 0) {
		o.message("Entry doesn't exist");
		return;
	}
	float f = currentSummary->getValue(str);
	currentSummary->remove(str);
	o.message("Removed " + str + " - " + std::to_string(f) + " from summary " + currentSummary->name);
}

void loaded() {
	if (currentSummary == nullptr) {
		o.message("No summary loaded");
		return;
	}
	o.message("Current Summary: " + currentSummary->name,o.blue);
}
void quit() {
	o.message("Goodbye");
	running = false;
}

void getAction() {
	std::string str = c.command();
	if (str == NEW) {
		newSummary();
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
	else if (str == LOADED) {
		loaded();
		return;
	}
	else if (str == SAVE) {
		saveSummary();
		return;
	}
	else if (str == COPY) {
		copySummary();
		return;
	}
	else if (str == RENAME) {
		renameSummary();
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
	else if (str == LIST) {
		o.printSummariesList(summaries);
		return;
	}
	else if (str == CLEAR) {
		o.clearScreen();
		return;
	}
	o.message("Wrong command entered, try again");
}
void loadToSummaries() {
	summaries =	f.loadDirectory();
}
void clean() {
	summaries.clear();
	o.message("Cleared List");
}


int main() {
	//program loop
	system("Title FinanApp \xa9 Mirco Baalmans");

	loadToSummaries();
	o.message("Use 'help' to see all available commands", o.cyan);
	while (running) {
		o.message("Enter a command",o.cyan);
		c.getInput();
		getAction();
	}
	saveSummary();
	clean();
	return 0;
}

