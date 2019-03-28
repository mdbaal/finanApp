#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <string>
#include <sstream>
#include "summary.h"
#include "output.h"

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

class Filehandler{
public:
	Filehandler();
	virtual ~Filehandler();

	void saveToFile(Summary* current);
	Summary* loadFromFile(std::string _s);
	//function that returns a map of all summaries in a directory
	std::map<std::string,Summary*> loadDirectory();
	bool deleteFile(std::string str);
private:
	Output o = Output();
};

#endif //FILEHANDLER_H
