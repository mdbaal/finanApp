#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <string>
#include "summary.h"
#include "output.h"

class Filehandler{
public:
	Filehandler();
	virtual ~Filehandler();

	void saveToFile(Summary* current);
	Summary loadFromFile(std::string _s);

private:
	Output o = Output();
};

#endif //FILEHANDLER_H
