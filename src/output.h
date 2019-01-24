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
	void message(std::string msg) { std::cout << msg << std::endl; }
	
private:

};

#endif //OUTPUT_H