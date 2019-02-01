#ifndef OUTPUT_H
#define OUTPUT_H

#include "summary.h"
#include <iostream>
#include <string>

class Output{
public:
	Output();
	virtual ~Output();

	void drawSummary(Summary* s);
	void message(std::string msg) { std::cout << std::endl << msg << std::endl; }
	void printHelp();
private:

};

#endif //OUTPUT_H