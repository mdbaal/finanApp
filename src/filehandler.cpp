#include "filehandler.h"


Filehandler::Filehandler(){

}

Filehandler::~Filehandler(){


}

void Filehandler::saveToFile(Summary* current) {
	if (current == nullptr) return;
	std::ofstream file;

	file.open("summaries/" + current->name + ".txt", std::iostream::trunc);

	if (file.fail()) {
		o.message("Can't open file");
		return;
	}

	file << current->name << std::endl;
	if (!current->getMap().empty()) {
		for (auto const& x : current->getMap()) {
			file << x.first << std::endl;
			file << x.second << std::endl;
		}
	}
	file.close();
}

Summary* Filehandler::loadFromFile(std::string _s) {
	std::ifstream file;
	std::string str = "";
	std::string name = "";
	float f = 0;
	bool isfloat = false;
	Summary* s = new Summary();
	s->name = "summary";

	file.open("summaries/" + _s + ".txt");

	if (file.fail()) {
		o.message("Can't open file");
		delete s;
		return nullptr;
	}
	else {

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
		return s;
	}
}

std::map<std::string, Summary*> Filehandler::loadDirectory() {
	std::string dir = "summaries/";
	std::string filename;
	std::istringstream entryPath;
	std::map<std::string, Summary*> _map = std::map<std::string,Summary*>();
	Summary* s = nullptr;

	for (const auto & entry : fs::directory_iterator(dir)) {
		entryPath.str(entry.path().filename().string());
		std::getline(entryPath,filename,'.');
		s = loadFromFile(filename);		
		_map.insert_or_assign(s->name, s);
	}

	return _map;
}


bool Filehandler::deleteFile(std::string str) {
	std::string _str = str.append(".txt");
	if (std::remove(("summaries/" + _str).c_str()) == 0) {
		return true;
	}
	else {
		return false;
	}
}